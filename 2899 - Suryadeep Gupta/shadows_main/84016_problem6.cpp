#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<string> S1(N), S2(N);
        for (int i = 0; i < N; i++) cin >> S1[i];
        for (int i = 0; i < N; i++) cin >> S2[i];
        
        // S1 is projection onto XZ plane (left wall): row=y(top-down), col=x
        // S2 is projection onto YZ plane (right wall): row=y(top-down), col=z
        // A block at (x, y, z) exists if S1[y][x]=='#' AND S2[y][z]=='#'
        
        // Max volume: place block at (x,y,z) if S1[y][x]=='#' AND S2[y][z]=='#'
        long long maxVol = 0;
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++)
                for (int z = 0; z < N; z++)
                    if (S1[y][x] == '#' && S2[y][z] == '#')
                        maxVol++;
        
        // Min volume: for each (row y, col x) that is '#' in S1,
        // we need at least one z such that S2[y][z]=='#'.
        // For each (row y, col z) that is '#' in S2,
        // we need at least one x such that S1[y][x]=='#'.
        // Minimum cover: for each row y, we need to cover all '#' in S1[y] and S2[y]
        // using minimum blocks. This is a set cover / bipartite matching per row.
        // 
        // Per row y: let A = set of x where S1[y][x]=='#'
        //            let B = set of z where S2[y][z]=='#'
        // We need a set of (x,z) pairs with x in A, z in B such that
        // every x in A appears in at least one pair, and every z in B appears in at least one pair.
        // Minimum such set = max(|A|, |B|)
        
        long long minVol = 0;
        for (int y = 0; y < N; y++) {
            int cntA = 0, cntB = 0;
            for (int x = 0; x < N; x++) if (S1[y][x] == '#') cntA++;
            for (int z = 0; z < N; z++) if (S2[y][z] == '#') cntB++;
            minVol += max(cntA, cntB);
        }
        
        cout << maxVol << " " << minVol << "\n";
    }
    
    return 0;
}

void read_your_input() {
    // reads T test cases, each with N, then N lines for S1, then N lines for S2
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<string> S1(N), S2(N);
        for (int i = 0; i < N; i++) cin >> S1[i];
        for (int i = 0; i < N; i++) cin >> S2[i];
    }
}