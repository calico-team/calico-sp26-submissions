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
  int N;
  cin >> N;

  vector<int> s1, s2;
  s1.resize(N);
  s2.resize(N);


  string _s;
  int _cnt;

  FOR(i, 0, N) {
    cin >> _s;
    _cnt = 0;
    for(char c : _s) _cnt += (c == '#');
    s1[i] = _cnt;
  }

  FOR(i, 0, N) {
    cin >> _s;
    _cnt = 0;
    for(char c : _s) _cnt += (c == '#');
    s2[i] = _cnt;
  }

  int mx = 0, mn = 0;

  FOR(h, 0, N) {
    mx += s1[h] * s2[h];
    mn += max(s1[h], s2[h]);
  }
 
  cout << mx << " " << mn << endl;

}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q;
  while(Q--) solve();

  return 0;
}
