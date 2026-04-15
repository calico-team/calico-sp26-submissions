#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a; i<b; i++)

using namespace std;



void solve(){
    int n, p, r, k;
    cin >> n >> p >> r >> k;
    vector<int> vec(n);
    rep(i,0,n)cin>> vec[i];

    bool ok = 1;
    rep(i,0,n){
        p -= vec[i];
        if(p < 0){
            ok = 0;
            break;
        }
        if((i+1) % k == 0){
            p += r;
        }
    }

    if(ok) cout << "nah i’d win\n";
    else cout << "nah i’d lose\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}