#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
    while (t--) {
        int k, n, m, p, q, x, y; cin >> k >> n >> m >> p >> q;
        unordered_map<int,int> a;
        for (int i = 0; i < k; i++) {
            int e, f; cin >> e >> f;
            a[e*1e4+f] = i;
            if (!i) {
                x = e;
                y = f;
            }
        }
        do {
            x = (x+q)%n;
            y = (y+p)%m;
        } while (!a.count(x*1e4+y));
        cout << a[x*1e4+y] << endl;
    }
}