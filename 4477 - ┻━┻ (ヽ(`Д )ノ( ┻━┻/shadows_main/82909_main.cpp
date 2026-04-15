#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3;
int N, T, g[2][MM+1][MM+1], ps[2][MM+1];

void solve(){
    cin >> N;
    for (int k = 0; k < 2; k++){
        for (int r = 1; r <= N; r++){
            string s;
            cin >> s;
            ps[k][r] = 0;
            for (int c = 1; c <= N; c++){
                g[k][r][c] = (s[c-1] == '#');
                ps[k][r] += g[k][r][c];
            }
        }
    }
    int mn = 0,  mx = 0;
    // computing max
    for (int r = 1; r <= N; r++){
        for (int c = 1; c <= N; c++){
            if (g[0][r][c]) mx += ps[1][r];
        }
    }
    // computing min
    for (int r = 1; r <= N; r++) mn += max(ps[0][r], ps[1][r]);
    cout << mx << " " << mn << "\n";
}

int main(){
    cin >> T;
    for (; T > 0; T--) solve();
}