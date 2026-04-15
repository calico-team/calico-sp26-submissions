#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<string> S1(N);
    for (int i = 0; i < N; ++i) {
        cin >> S1[i];
    }

    vector<string> S2(N);
    for (int i = 0; i < N; ++i){
        cin >> S2[i];
    }
    
    long long max_vol= 0;
    long long min_vol = 0;
    

    for (int i = 0; i < N; ++i){
        long long c1 = 0;
        long long c2 = 0;

        for (int j = 0; j < N; ++j) {
            if (S1[i][j] == '#') c1++;
        }

        for (int j = 0; j < N; ++j){
            if (S2[i][j] == '#') c2++;
        }

        max_vol += (c1 * c2);
        min_vol += max(c1, c2);
    }
cout << max_vol << " " << min_vol << "\n";
}



int main() {


    int T;
    if (cin >> T){
        while (T--){
            solve();
        }
    }
    return 0;
}