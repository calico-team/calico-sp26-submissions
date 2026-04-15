#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int MV = 1e18;

void solve(){
    int n, p, r, k;
    cin >> n >> p >> r >> k;
    vector<int> a(n);
    bool pos = true;
    int kil = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > p){
            pos = false;
        }
        p -= a[i];
        kil++;
        if(kil % k == 0) p += r;
    }
    if(pos) cout << "nah i'd win\n";
    else cout << "nah i'd lose\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}