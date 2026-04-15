#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	string a, b;
    cin >> a >> b;
    for(int i = 0, j = 0; i < a.size();) {
        if(j == b.size() || a[i] != b[j]) {
            cout << '#';
            i++;
        } else {
            cout << a[i];
            i++; j++;
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}