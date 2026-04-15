/**
 *    author:  tourist
 *    created: 11.04.2026 22:40:27
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t p;
    int a, b;
    cin >> p >> a >> b;
    vector<int> d(a + b);
    for (int i = a + b - 1; i >= b; i--) {
      d[i] = int(p % 2);
      p /= 2;
    }
    for (int i = b - 1; i >= 0; i--) {
      d[i] = int(p % 3);
      p /= 3;
    }
    if (p == 1) {
      cout << "1 1" << '\n';
      cout << ">" << '\n';
      continue;
    }
    vector<string> s(4, string(4 * (a + b), '.'));
    s[0] = s[3] = string(4 * (a + b), '>');
    for (int i = 0; i < a + b; i++) {
      s[0][4 * i + 1] = 'v';
      s[1][4 * i + 1] = '>';
      s[1][4 * i + 2] = 'S';
      s[2][4 * i + 2] = (d[i] >= 1 ? 'v' : 'X');
      if (i < b) {
        s[1][4 * i + 3] = 'v';
        s[2][4 * i + 3] = (d[i] >= 2 ? 'v' : 'X');
      }
    }
    s[0].back() = 'X';
    cout << 4 << " " << 4 * (a + b) << '\n';
    for (int i = 0; i < 4; i++) {
      cout << s[i] << '\n';
    }
  }
  return 0;
}
