#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(),v.end());
    if(v.size()%2==1) {
        for(int i = 0; i < n; i++) {
            cout << v[v.size()/2] << " ";
        }
    } 
    else {
        int med1 = v[v.size()/2], med2 = v[v.size()/2-1];
        for(int i = 0; i < n; i++) {
            if(v[i] >= med1)  cout << med1 << " ";
            else cout << med2 << " ";
        }
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        solve();
    }
} 
