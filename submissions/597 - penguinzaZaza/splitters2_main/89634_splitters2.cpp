#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, int> red(pair<int, int> a) {
  if (a.first <= 0 && a.second <= 0) {
    a.first *= -1, a.second *= -1;
  }
  int x = __gcd(a.first, a.second);
  if (x == 0) {
    return a;
  }
  return {a.first / x, a.second / x};
}
pair<int, int> add(pair<int, int> a, pair<int, int> b) {
  int num = a.first * b.second + b.first * a.second, den = a.second * b.second;
  return red({num, den});
}
int stu(int a, int b) {
  int x = 1;
  while (b--) {
    x *= a;
  }
  return x;
}
bool les(pair<int, int> a, pair<int, int> b) {
  return a.first * b.second <= a.second * b.first;
}
signed main() {
  // cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int p, a, b;
    cin >> p >> a >> b;

    vector<string> vs(3, string(2 * (a + b) + 2, '.'));

    vs[0][0] = 'v';
    vs[1][0] = '>';

    int in = 1;
    while (pow(2.0, a) * pow(3.0, b) > 1e18) {
      vs[1][in + 1] = '>';
      vs[1][in] = 'S';
      if (b > 0) {
        b--;
        vs[0][in] = 'X';
        vs[2][in] = 'X';
      } else {
        a--;
        vs[0][in] = 'X';
      }

      in += 2;
    }

    // cout << a << " " << b << "\n";

    pair<int, int> cur = {1, 1}, lef = {p, stu(2, a) * stu(3, b)};

    while (b > 0) {

      int idk = __gcd(cur.second, lef.second);
      cur.second *= idk;
      lef.second *= idk;
      // cout << cur.first << " " << cur.second << " " << lef.first << " "
      //      << lef.second << "\n";
      vs[1][in + 1] = '>';
      vs[1][in] = 'S';
      pair<int, int> dec;
      if (les(red({cur.first * 2, cur.second * 3}), lef)) {
        vs[0][in] = '^';
        vs[2][in] = 'v';
        dec = {-2 * cur.first, 3 * cur.second};
      } else if (les(red({cur.first, cur.second * 3}), lef)) {
        vs[0][in] = '^';
        vs[2][in] = 'X';
        dec = {-cur.first, 3 * cur.second};
      } else {
        vs[0][in] = 'X';
        vs[2][in] = 'X';
        dec = {0, 1};
      }

      lef = add(lef, dec);
      cur.second *= 3;

      in += 2;
      b--;
    }

    // cout << "??\n";

    while (a > 0) {
      int idk = __gcd(cur.second, lef.second);
      cur.second /= idk;
      lef.second /= idk;
      // cout << cur.first << " " << cur.second << " " << lef.first << " "
      //      << lef.second << "\n";
      vs[1][in + 1] = '>';
      vs[1][in] = 'S';
      pair<int, int> dec;
      if (les(red({cur.first, cur.second * 2}), lef)) {
        vs[0][in] = '^';
        dec = {-cur.first, 2 * cur.second};
      } else {
        vs[0][in] = 'X';
        dec = {0, 1};
      }

      // cout << dec.first << " " << dec.second << "\n";

      lef = add(lef, dec);
      cur.second *= 2;

      in += 2;
      a--;
    }
    vs[1].back() = 'X';

    cout << vs.size() << " " << vs[0].size() << "\n";
    for (auto a : vs)
      cout << a << "\n";
  }
}
