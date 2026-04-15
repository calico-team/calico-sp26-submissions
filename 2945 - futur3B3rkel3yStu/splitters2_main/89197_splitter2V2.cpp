#include <bits/stdc++.h>
using namespace std;

static long long pp;

vector<string> solve(int P, int A, int B) {
  long long p = pp;
  const long long lm = 1000000000000LL + 1;

  vector<long long> p2(101), p3(101);
  p2[0] = 1;
  for (int i = 1; i <= 100; i++) {
    __int128 v = (__int128)p2[i - 1] * 2;
    p2[i] = (v > lm ? lm : (long long)v);
  }
  p3[0] = 1;
  for (int i = 1; i <= 100; i++) {
    __int128 v = (__int128)p3[i - 1] * 3;
    p3[i] = (v > lm ? lm : (long long)v);
  }

  auto dv = [&](int a, int b) -> long long {
    __int128 v = (__int128)p2[a] * p3[b];
    if (v > lm) return lm;
    return (long long)v;
  };

  int n = A + B;
  int h = 7;
  int m = 2 * n + 3;
  vector<string> g(h, string(m, '.'));

  g[0][0] = 'v';
  g[1][0] = 'v';
  g[2][0] = 'v';
  g[3][0] = '>';
  g[3][1] = '>';

  int a = A, b = B;

  for (int i = 0; i < n; i++) {
    int c = 2 + 2 * i;

    g[3][c] = 'S';
    g[3][c + 1] = '>';

    int k = (i < A ? 2 : 3);
    int a2 = a, b2 = b;
    if (k == 2) a2--;
    else b2--;

    long long dn = dv(a2, b2);
    long long d = 0;
    if (dn < lm) d = p / dn;

    if (k == 2) {
      if (d == 1) {
        g[2][c] = '^';
        g[1][c] = '^';
        g[0][c] = '^';
      } else {
        g[2][c] = 'x';
      }
    } else {
      if (d >= 1) {
        g[2][c] = '^';
        g[1][c] = '^';
        g[0][c] = '^';
      } else {
        g[2][c] = 'x';
      }
      if (d == 2) {
        g[4][c] = 'v';
        g[5][c] = 'v';
        g[6][c] = 'v';
      } else {
        g[4][c] = 'x';
      }
    }

    if (dn < lm) p -= d * dn;
    a = a2;
    b = b2;
  }

  g[3][m - 1] = 'x';
  return g;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    long long p;
    int A, B;
    cin >> p >> A >> B;
    pp = p;

    vector<string> fc = solve(0, A, B);
    int N = (int)fc.size();
    int M = (int)fc[0].size();
    cout << N << ' ' << M << '\n';
    for (auto &rw : fc) cout << rw << '\n';
  }
  return 0;
}