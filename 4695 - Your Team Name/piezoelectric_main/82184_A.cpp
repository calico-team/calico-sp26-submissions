#include <bits/stdc++.h>
using namespace std;

int l, w, t, e, r;

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> l >> w >> e >> r;
    int s = l + l + w + w;
    int steps = (e / r);
    cout << steps / s << '\n';
  }
}
