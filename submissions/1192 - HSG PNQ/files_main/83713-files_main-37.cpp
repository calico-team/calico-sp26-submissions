// soab

#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define nl '\n'

void io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}   

signed main() {
    io();

    int t; cin >> t;
    while(t--) {
        string a, b; cin >> a >> b;
        int n = a.size();
        int m = b.size();

        int j = 0;
        for(int i = 0; i < n; i++) {
            if(j < m && a[i] == b[j]) {
                cout << a[i];
                j++;
            } else {
                cout << "#";
            }
        }
        cout << nl;
    }

    return 0;
}   