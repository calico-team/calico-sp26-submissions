#include <bits/stdc++.h>
using namespace std;

// We'll build a factory row by row as a sequence of modules stacked vertically.
// Each module is 3 rows tall and handles one splitter stage.
// 
// Layout for a "halving" module (splits 1/2 off):
// Row 0: >vX   (flow comes in from left, splitter below, X = collect or destroy)
// Row 1: .S>   (splitter: sends up -> X, sends right -> continue)
// Row 2: ...   (empty or routing)
//
// We'll use a simpler linear horizontal layout.
// 
// APPROACH: build a 3-row grid.
// Row 1 (middle) is the "main line": items travel right through splitters.
// Each splitter in the main line sends 1/2 up or 1/3 in some direction.
// 
// For halving splitter: 2 valid neighbors -> each gets 1/2
// For thirding splitter: 3 valid neighbors -> each gets 1/3

// Simple linear chain approach:
// 3 rows, variable columns
// Main flow goes along middle row (right)
// Each splitter stage takes up 2 columns:
//   col c: splitter (S), col c+1: collect(^) or destroy(X) in row above, continue(>) in middle

// For A halvings: each halving = 1 splitter with 2 outputs (up = branch, right = continue)
// For B thirdings: each thirding = 1 splitter with 3 outputs (up, right, down = branches)
// 
// The "collect or destroy" is determined by the fraction decomposition.
//
// Fraction decomposition:
// We want to collect P/(2^A * 3^B).
// Process halvings first, then thirdings.
// At each halving stage i (i=0..A-1):
//   current denominator = 2^(A-i) * 3^B, current flow = 1
//   splitting gives 1/2 to branch, 1/2 continues
//   branch fraction = 1/(2^(A-i) * 3^B)
//   if P >= branch_contribution: collect, P -= contribution; else destroy
//
// This is essentially writing P in a mixed-radix system.

// Let's implement: for each halving, the "split off" amount is 2^(A-1-i) * 3^B
// (when current flow is 2^(A-i) * 3^B units out of total 2^A*3^B)
// Actually let's track numerically.

// We'll use big integers via __int128 or just long long (P <= 10^12, 2^A*3^B can be huge but we just need logic)

// Key: represent everything as fractions with denominator 2^A * 3^B
// Current "stream" starts at numerator = 2^A * 3^B (= whole thing)
// At each halving splitter: stream splits into stream/2 (branch) and stream/2 (continue)
//   collect branch if P >= stream/2: P -= stream/2, branch = collect; else branch = destroy
//   stream = stream/2
// At each thirding splitter: stream splits into stream/3 each (3 branches, one continues)
//   We have 2 branches to assign: both collect, both destroy, or one each
//   Greedily: each branch = stream/3
//   assign branches: 
//     branch1: if P >= stream/3 -> collect, P -= stream/3; else destroy
//     branch2: if P >= stream/3 -> collect, P -= stream/3; else destroy
//   stream = stream/3

// Grid layout:
// 3 rows. 
// Halving module (2 cols wide, col c and c+1):
//   row 0, col c: '^' or 'X' (branch output - goes up/out, or destroy)
//   row 1, col c: 'S' (splitter)
//   row 1, col c+1: '>' (continue right)
//   row 2, col c: '.' 
//   row 2, col c+1: '.'
//   splitter at (1,c) has valid neighbors: (0,c) [up, not pointing back] and (1,c+1) [right conveyor]
//   Wait - need (0,c) to be '^' pointing up (away from splitter) - valid (not pointing back)
//   and (1,c+1) to be '>' pointing right - valid

// Thirding module (3 cols wide, col c..c+2):
//   row 0, col c: '^' or 'X'  (branch 1)
//   row 1, col c: 'S'
//   row 2, col c: 'v' or 'X'  (branch 2) - 'v' pointing down = exits grid if row 2 is last row
//   row 1, col c+1: '>' (continue)
//   But we need row 2 col c to exit or be destroy.
//   If 'v' at row 2 (bottom row of 3-row grid), it exits -> collect
//   If 'X' at row 2 -> destroy

// Start: row 1, col 0: '>' leading into first splitter? No, items start top-left.
// Items start at (0,0). So we need to route from (0,0) to the main line at row 1.
// 
// Add a leading column: col 0 = 'v' at row 0, '>' at row 1 to enter splitter chain.
// Actually start col: 
//   (0,0) = 'v', (1,0) = '>' -> this routes to (1,1) which is first splitter or conveyor

// Let me just build the grid as a 2D vector and place tiles.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--) {
        long long P, A, B;
        cin >> P >> A >> B;
        
        // We'll build a 3-row grid.
        // Compute number of columns needed:
        // 1 col for entry + A*2 cols for halvings + B*3 cols for thirdings + 1 col for final exit
        // Actually let's compute and build.
        
        // Track current stream as a fraction: numerator over 2^A * 3^B
        // Use __int128 to be safe
        typedef long long ll;
        // denominator = 2^A * 3^B, but can be huge (up to 2^100 * 3^100)
        // We can't store it as integer. Instead track stream as (num_2, num_3) exponents.
        // stream = 2^s2 * 3^s3 (as a power-of-2-power-of-3 number)
        // P is just an integer <= 10^12
        
        // At each halving: branch = stream/2, continue = stream/2
        //   branch as fraction of total = stream/2 / (2^A*3^B) = 2^(s2-1)*3^s3 / (2^A*3^B)
        //   in terms of "units" where unit = 1/(2^A*3^B):
        //   branch_units = 2^(s2-1-0)*3^(s3) * ... hmm
        //   Actually: stream (as units) starts at 2^A*3^B units. 
        //   Each halving: branch_units = stream_units/2
        //   Each thirding: branch_units = stream_units/3
        //   P is in the same "units" (P out of 2^A*3^B)
        // 
        // But stream_units can be up to 2^A*3^B which is astronomically large.
        // However, we only need to compare P with stream_units/2 or stream_units/3.
        // We can track stream_units as (exp2, exp3) and compare with P:
        //   stream_units/2 = 2^(exp2-1) * 3^exp3
        //   Is P >= 2^(exp2-1) * 3^exp3? 
        //   If exp2-1 + exp3*log2(3) > log2(10^12) ~ 40, then yes (P is always less).
        //   If small enough, compute directly.
        
        // Since P <= 10^12 < 2^40, if 2^(exp2-1)*3^exp3 > 10^12, branch_units > P always -> destroy.
        // We can use this.
        
        auto branch_val = [&](ll e2, ll e3) -> ll {
            // compute 2^e2 * 3^e3, return -1 if overflow 2*10^12
            ll val = 1;
            for(int i = 0; i < e2; i++) {
                if(val > 2e12) return -1; // overflow sentinel
                val *= 2;
            }
            for(int i = 0; i < e3; i++) {
                if(val > 2e12) return -1;
                val *= 3;
            }
            return val;
        };
        
        // Build sequence of actions
        // Each action: type (H=halving, T=thirding), and for H: collect/destroy branch
        // For T: collect/destroy branch1, collect/destroy branch2
        
        struct Action {
            char type; // 'H' or 'T'
            bool b1, b2; // collect(true) or destroy(false) for each branch
        };
        vector<Action> actions;
        
        ll stream_e2 = A, stream_e3 = B; // stream = 2^stream_e2 * 3^stream_e3 units
        ll p = P;
        
        for(int i = 0; i < A; i++) {
            // halving: branch = stream/2 = 2^(stream_e2-1) * 3^stream_e3
            stream_e2--;
            ll bv = branch_val(stream_e2, stream_e3);
            bool collect = false;
            if(bv != -1 && p >= bv) {
                collect = true;
                p -= bv;
            }
            actions.push_back({'H', collect, false});
        }
        for(int i = 0; i < B; i++) {
            // thirding: each branch = stream/3 = 2^stream_e2 * 3^(stream_e3-1)
            stream_e3--;
            ll bv = branch_val(stream_e2, stream_e3);
            bool c1 = false, c2 = false;
            if(bv != -1 && p >= bv) { c1 = true; p -= bv; }
            if(bv != -1 && p >= bv) { c2 = true; p -= bv; }
            actions.push_back({'T', c1, c2});
        }
        
        // Final stream_e2==0, stream_e3==0 -> stream = 1 unit left
        // This last piece: if p==1 collect, else destroy (but p should be 0 now if not collected)
        // Actually the "continue" path at the end needs to exit too.
        // After all splitters, the remaining stream (1 unit) exits at the end.
        // If p==1: it should be collected. If p==0: destroy it.
        bool final_collect = (p == 1);
        // p should now be 0 after this.
        
        // Now build the grid.
        // 3 rows. Columns:
        // col 0: entry (route from top-left down to row 1)
        //   (0,0)='v', (1,0)='>', (2,0)='.'
        // Then for each halving action: 2 cols
        //   col c, c+1
        //   (0,c) = collect?'^':'X'
        //   (1,c) = 'S'
        //   (1,c+1) = '>'
        //   (2,c) = '.'  (2,c+1)='.'
        // For each thirding action: 3 cols
        //   col c, c+1, c+2
        //   (0,c) = c1?'^':'X'
        //   (1,c) = 'S'
        //   (2,c) = c2?'v':'X'
        //   (1,c+1) = '>' 
        //   cols c+2: just padding? No we need c+1 to route to next splitter at c+2... 
        //   Wait: after S at col c, continue goes right to (1,c+1)='>'. 
        //   Then (1,c+2) is the next S or conveyor.
        //   But we only used 2 cols (c and c+1) for thirding too if continue is at c+1.
        //   The splitter at (1,c) has 3 valid neighbors: up (0,c), down (2,c), right (1,c+1).
        //   That's 3 neighbors -> thirding. 
        //   So thirding also takes 2 columns! Great.
        
        // So each action (H or T) takes 2 columns.
        // Final: 1 column for the exit.
        //   If final_collect: (1, last_col)='^' exits top. Actually '>' at last col exits right.
        //   Or just: (1, last_col) = final_collect ? '>' : 'X'
        //   But '>' at the rightmost column exits right -> collected.
        //   'X' -> destroyed.
        //   Actually the '>' at (1,c+1) of last action already points right to next col.
        //   The next col is the final exit. So (1, final_col) = final_collect ? '>' : 'X'.
        
        int num_actions = (int)actions.size(); // = A+B
        int total_cols = 1 + num_actions * 2 + 1;
        int total_rows = 3;
        
        // Check tile count
        // total_rows * total_cols = 3 * (2 + 2*(A+B)) = 3*(2+2*100) = 3*202 = 606 <= 2000. Good.
        
        vector<string> grid(total_rows, string(total_cols, '.'));
        
        // Entry
        grid[0][0] = 'v';
        grid[1][0] = '>';
        
        int col = 1;
        for(auto& act : actions) {
            // Splitter at (1, col)
            grid[1][col] = 'S';
            // Up branch
            grid[0][col] = act.b1 ? '^' : 'X';
            if(act.type == 'T') {
                // Down branch
                grid[2][col] = act.b2 ? 'v' : 'X';
            }
            // Continue right
            grid[1][col+1] = '>';
            col += 2;
        }
        
        // Final exit at col
        grid[1][col] = final_collect ? '>' : 'X';
        // If '>', it exits right (off grid) -> collected. Good.
        
        cout << total_rows << " " << total_cols << "\n";
        for(auto& row : grid) cout << row << "\n";
    }
    
    return 0;
}