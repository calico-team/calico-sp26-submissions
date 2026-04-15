#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;


void solve() {
    int v[1000][1000] = {-1};

    int n, m;
    cin >> m >> n;

    int start[] = {0, 2, 4, 1, 3};
    for (int x=0; x<m; x++) {
        int a = start[x % 5];
        for (int y=0; y<n; y++) {
            v[x][y] = a;
            a = (a + 1) % 5;
        }
    }

    /*
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (!validate(x, y, v[x][y])) {
                cout << "failed" << endl;;
            }
        }
    }
    */

    for (int x=0; x<m; x++) {
        for (int y=0; y<n; y++) {
            cout << v[x][y];
            if (y < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
}

int32_t main() {
	int t;
    cin >> t;
    while (t--) solve();
}
