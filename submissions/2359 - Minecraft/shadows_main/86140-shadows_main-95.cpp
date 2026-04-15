#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vector<string> S1(n), S2(n);
        for(int i = 0; i < n; i++) cin >> S1[i];
        for(int i = 0; i < n; i++) cin >> S2[i];
        vector<int> cnt1(n, 0), cnt2(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(S1[i][j] == '#') cnt1[j]++;
                if(S2[i][j] == '#') cnt2[j]++;
            }
        }
        long long max_vol = 0, min_vol = 0;
        for(int z = 0; z < n; z++) {
            max_vol += 1LL * cnt1[z] * cnt2[z];
            min_vol += max(cnt1[z], cnt2[z]);
        }
        cout << max_vol << " " << min_vol << endl;
    }
    return 0;
}