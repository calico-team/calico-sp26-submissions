#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    vector<int> a(n); for(int &x : a) cin >> x;

    int basesum = 0;

    for(int i = 1; i < n; ++i){
        basesum += abs(a[i]-a[i-1]);
    }

    vector<int> L(n,a[0]), R(n,a[0]);

    vector<int> v;

    for(int i = 1; i < n; ++i){
        v.push_back(L[i-1]);
        v.push_back(R[i-1]); 
        v.push_back(a[i]); v.push_back(a[i]);

        sort(v.begin(),v.end());

        L[i] = v[1];
        R[i] = v[2];

        v.resize(0);
    }

    vector<int> b(n);
    
    b[n-1] = L[n-1];

    for(int i = n - 2; i >= 0; --i){
        b[i] = max(L[i], min(R[i], b[i+1]));
    }

    for(int i : b){
        cout << i << " ";
    }

    cout << "\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--) solve();

}