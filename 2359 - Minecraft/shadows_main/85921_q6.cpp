#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {     
        int n;
        cin >> n;
        vector<string> S1(n);
        for(int j = 0; j < n; j++) {   
            cin >> S1[j];
        }
        vector<string> S2(n);
        for(int j = 0; j < n; j++) {
            cin >> S2[j];
        }
        vector<int> cnt1(n, 0), cnt2(n, 0);
        for(int x = 0; x < n; x++) {
            for(int z = 0; z < n; z++) {
                if(S1[x][z] == '#') cnt1[z]++;
                if(S2[x][z] == '#') cnt2[z]++;
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