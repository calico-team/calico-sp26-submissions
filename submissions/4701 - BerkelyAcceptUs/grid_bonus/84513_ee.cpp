#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int MV = 1e18;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n), res(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    l[0] = r[0] = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] < l[i-1]){
            l[i] = a[i];
            r[i] = l[i-1];
        } else if(a[i] > r[i-1]){
            l[i] = r[i-1];
            r[i] = a[i];
        } else{
            l[i] = r[i] = a[i];
        }
    }
    res.back() = l.back();
    for(int i = n-2; i >= 0; i--){
        if(res[i+1] < l[i]) res[i] = l[i];
        else if(res[i+1] > r[i]) res[i] = r[i];
        else res[i] = res[i+1];
    }
    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}