#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    int j = 0; // index for a
    for (int i=0; i<b.length(); i++) {
        while (a[j] != b[i]) {
            a[j] = '#';
            j++;
        }
        j++;
    }

    while (j<a.length()) {
        a[j] = '#';
        j++;
    }
    cout << a << endl;
}

int32_t main() {
	int t;
    cin >> t;
    while (t--) solve();
}
