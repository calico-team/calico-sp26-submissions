#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int a = v[0],  b = v[1], c = v[2];

    if((a+c)%2==0) {
        int avg = (a+c)/2;
        cout << avg << " " << avg << " " << avg << endl;
    }
    else {
        int curr = (a+c)/2;
        if(curr < v[1]) curr++;
        cout << curr << " " << curr << " " << curr << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        solve();
    }
} 
