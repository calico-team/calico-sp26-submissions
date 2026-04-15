#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<ll> A(N);
        for(auto &x : A) cin >> x;
        
        // Minimize sum_{i<N-1}|b[i]-b[i+1]| + sum_i|b[i]-A[i]|
        // Slope trick:
        // f_i(x) = min over b[1..i] with b[i]=x
        // f_1(x) = |x - A[0]|
        // f_i(x) = min_y(f_{i-1}(y) + |y-x|) + |x-A[i]|
        // The "min_y(g(y)+|y-x|)" operation is the "L1 proximity" = sliding window of width 0
        // which extends the flat region by 1 on each side (infimal convolution with |x|)
        // meaning: if g has slope breakpoints L (left heap, max-heap) and R (right heap, min-heap)
        // then after infimal conv with |x|, subtract 1 from leftmost right breakpoint and add 1 to rightmost left breakpoint
        // i.e., L's max decreases by 1 and R's min increases by 1... 
        // Actually infimal convolution with c*|x| extends the flat region by c on each side.
        // Here c=1, so L_max -= 1 is wrong conceptually; the operation just shifts L top down by 1 and R top up by 1
        // But since breakpoints are integers, effectively: pop L max -> push L max-1? No.
        // 
        // Correct slope trick for |y-x|: infimal convolution extends flat part by 1 each side.
        // Implementation: L_max -> L_max (no pop needed, just conceptually shift),
        // but standard implementation: after inf conv with |t|, the new L_top = old L_top - 1... 
        // Actually the standard way: inf conv with |t| = extend flat region, done by:
        //   new_L_top = old_L_top (push old_L_top - 0... )
        // Let me just implement carefully.
        //
        // Standard slope trick for sum|b[i]-b[i+1]| + sum|b[i]-A[i]|:
        // Process left to right. Maintain L (max-heap, left breakpoints) and R (min-heap, right breakpoints).
        // Adding |x - A[i]|: push A[i] to L, push A[i] to R, then balance.
        // Adding |b[i-1] - b[i]| (transition): inf conv with |t|: L_top--, R_top++ (lazy with offset).
        
        // We track minimum value and reconstruct via backtracking.
        // For reconstruction, store the optimal b[i] range [l[i], r[i]] (the flat region endpoints).
        
        priority_queue<ll> L; // max-heap
        priority_queue<ll, vector<ll>, greater<ll>> R; // min-heap
        ll L_offset = 0, R_offset = 0;
        ll min_cost = 0;
        
        vector<ll> opt_l(N), opt_r(N);
        
        for(int i = 0; i < N; i++){
            if(i > 0){
                // inf conv with |t|: extend flat region by 1 each side
                L_offset -= 1;
                R_offset += 1;
            }
            // Add |x - A[i]|: push A[i] twice
            ll a = A[i];
            // Push to L
            L.push(a - L_offset);
            // Push to R  
            R.push(a - R_offset);
            // Balance: L_top <= R_top
            ll l_top = L.top() + L_offset;
            ll r_top = R.top() + R_offset;
            if(l_top > r_top){
                // swap tops
                L.pop(); R.pop();
                min_cost += l_top - r_top;
                L.push(r_top - L_offset);
                R.push(l_top - R_offset);
            }
            opt_l[i] = L.top() + L_offset;
            opt_r[i] = R.top() + R_offset;
        }
        
        // Reconstruct: go right to left, pick b[i] in [opt_l[i], opt_r[i]] 
        // and clamp to neighbor's value for continuity
        vector<ll> the_two_tower_heights(N);
        the_two_tower_heights[N-1] = max(opt_l[N-1], min(opt_r[N-1], A[N-1]));
        // clamp to [1, 2e9]
        the_two_tower_heights[N-1] = max(1LL, min((ll)2e9, the_two_tower_heights[N-1]));
        
        for(int i = N-2; i >= 0; i--){
            ll prev = the_two_tower_heights[i+1];
            // b[i] wants to be in [opt_l[i], opt_r[i]], and close to prev
            ll val = max(opt_l[i], min(opt_r[i], prev));
            val = max(1LL, min((ll)2000000000LL, val));
            the_two_tower_heights[i] = val;
        }
        
        for(int i = 0; i < N; i++){
            cout << the_two_tower_heights[i];
            if(i < N-1) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}

void read_your_input(){
    // T test cases, each: N, then N integers A[1..N]
}