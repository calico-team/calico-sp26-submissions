#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int l,w,e,r; cin >> l >> w >> e >> r;
        int p = 2*(l+r)*r;
        int laps=e/p;
        cout << laps << endl;
    }
}