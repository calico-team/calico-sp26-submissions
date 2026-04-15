#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int l, w, e, r;
    cin >> l >> w >> e >> r;
    cout << e / ((l + w) * 2) / r << endl;
  }
}
