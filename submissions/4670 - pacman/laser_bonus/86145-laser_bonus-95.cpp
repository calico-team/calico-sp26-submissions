#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int INF = 1e18;
int gcd(int a, int b, int& x, int& y){
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
bool solve(int a, int b, int m, int& res, int& mod) {
  int x, y;
  int g = gcd(a, m, x, y);
  if (b % g != 0) return false;
  mod = m / g;
  res = (x % mod + mod) % mod;
  res = ((res) * (b / g)) % mod;
  return true;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    vector < array < int, 2 > > a(k);
    for(int i = 0; i < k; i++){
      cin >> a[i][0] >> a[i][1];
    }
    int xs = a[0][0];
    int ys = a[0][1];
    int mn = INF;
    int ans = -1;
    for(int i = 0; i < k; i++){
      int tx = a[i][0];
      int ty = a[i][1];
      int dx = (tx - xs % n + n) % n;
      int dy = (ty - ys % m + m) % m;
      int a1, m1, a2, m2;
      if (!solve(q, dx, n, a1, m1)) continue;
      if (!solve(p, dy, m, a2, m2)) continue;
      int kv, sk;
      int diff = (a2 - a1 % m2 + m2) % m2;
      if(!solve(m1, diff, m2, kv, sk))continue;
      int id = a1 + kv * m1;
      int cmod = m1 * sk;
      if(id == 0)id = cmod;
      if(id < mn){
        mn = id;
        ans = i;
      }
    }
    cout << ans << "\n";
  }
}