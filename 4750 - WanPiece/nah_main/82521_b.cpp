#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve(){

    int n, p, r, k;
    cin >> n >> p >> r >> k;

    vector<int> a(n);
    for(auto &i : a) cin >> i;

    for(int i = 0; i < n; i++){
        if(i % k == 0 && i > 0) p += r;
        p -= a[i];
        if(p < 0){
            cout << "nah i'd lose" << endl;
            return;
        }
    }

    cout << "nah i'd win" << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;
    cin >> tc;
    while(tc--) solve();

}