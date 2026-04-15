#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    for (int i=0; i<n; i++ ) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    int vmin = 0, vmax = 0;

    for (int i=0; i<n; i++) {
        int r = 0, c = 0;
        for (int j=0; j<n; j++) {
            if (a[i][j] == '#') r++;
            if (b[i][j] == '#') c++;
        }
        vmax += r*c;
        vmin += max(r, c);
    }
    cout << vmax << " " << vmin << endl;
}

int32_t main() {
	int t;
    cin >> t;
    while (t--) solve();
}
