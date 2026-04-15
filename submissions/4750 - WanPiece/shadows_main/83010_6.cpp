#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){

    int n;
    cin >> n;

    vector<string> s1(n), s2(n);

    for(auto &i : s1) cin >> i;
    for(auto &i : s2) cin >> i;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s1[i][j] == '#') a[i]++;
            if(s2[i][j] == '#') b[i]++;
        }
    }

    int mn = 0;
    int mx = 0;

    for(int i = 0; i < n; i++){
        mn += max(a[i], b[i]);
        mx += a[i] * b[i];
    }

    cout << mx << ' ' << mn << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;
    cin >> tc;
    while(tc--) solve();

}