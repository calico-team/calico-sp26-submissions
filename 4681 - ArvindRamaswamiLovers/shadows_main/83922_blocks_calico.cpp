// Source: https://usaco.guide/general/io

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
        
        long long maxVol = 0, minVol = 0;
        
        for (int r = 0; r < N; r++) {
            int countS1 = 0, countS2 = 0;
            for (int c = 0; c < N; c++)
                if (S1[r][c] == '#') countS1++;
            for (int d = 0; d < N; d++)
                if (S2[r][d] == '#') countS2++;
            
            maxVol += (long long)countS1 * countS2;

            minVol += max(countS1, countS2);
        }
        
        cout << maxVol << " " << minVol << "\n";
    }
    
    return 0;
}