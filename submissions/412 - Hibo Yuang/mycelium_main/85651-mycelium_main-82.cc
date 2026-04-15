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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int Q;
int xm, ym, xg, yg;

void step(map<pair<int, int>, bool> &m, queue<pair<int, int>> &q, bool type, int &nexp, int &mcnt) {
  nexp++;
  int sz = q.size();
  FOR(_, 0, sz) {
    pair<int, int> cn = q.front();
    q.pop();

    FOR(d, 0, 4) {
      pair<int, int> newloc = mp(cn.f + dx[d], cn.s + dy[d]);
      if (m.find(newloc) == m.end()) { // not claiemd yet
        q.push(newloc);
        m[newloc] = type;
        if (!type) mcnt++;
      }
    }
  }
}

void solve() {
  cin >> xm >> ym >> xg >> yg;

  map<pair<int, int>, bool> m;
  // 0 is M
  // 1 is G

  m[mp(xm, ym)] = 0;
  m[mp(xg, yg)] = 1;

  int mcnt = 0;

  queue<pair<int, int>> qm, qg;

  qm.push(mp(xm, ym));
  qg.push(mp(xg, yg));

  int gexp= 1, mexp = 1; // each keeps count of how many times theyve expanded

  while(!qm.empty()) {
    // cout << qm.front().f << " " << qm.front().s;
    if (2 * gexp <= 7 * mexp) step(m, qg, 1, gexp, mcnt); // grass exp
    else  step(m, qm, 0, mexp, mcnt); // myc exp
  }

  cout << mcnt+1 << endl;

}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q;
  while(Q--) solve();

  return 0;
}
