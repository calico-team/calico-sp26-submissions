#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define f first
#define s second 
#define INF 0x3f3f3f3f
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int Q;

void solve() {
  string a, b;
  cin >> a >> b;

  int i = 0, j = 0;
  while(i < a.length()) {
    if (a[i] != b[j]) {
      a[i] = '#';
      i++;
    } else {
      i++; j++;
    }
  }

  cout << a << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q;

  while(Q--) solve();

  return 0;
}
