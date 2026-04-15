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
const int OFFSET = (int) 3000 * 1.5; 
const int MAX = (int) OFFSET * 2 + 1;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int Q;
int xm, ym, xg, yg;
signed char m[MAX][MAX];

// struct pair_hash {
//     inline size_t operator()(const std::pair<int, int> & v) const {
//         return std::hash<int>()(v.first) ^ std::hash<int>()(v.second) << 1;
//     }
// };

void step(signed char m[MAX][MAX], queue<pair<int, int>> &q, bool type, int &nexp, int &mcnt, pair<int, int> boundx, pair<int, int> boundy) {
  nexp++;
  int sz = q.size();
  FOR(_, 0, sz) {
    pair<int, int> cn = q.front();
    q.pop();

    FOR(d, 0, 4) {
      pair<int, int> newloc = mp(cn.f + dx[d], cn.s + dy[d]);
      // if (abs(newloc.f) > OFFSET || abs(newloc.s) > OFFSET) {
      if (newloc.f < boundx.f || newloc.f > boundx.s || newloc.s < boundy.f || newloc.s > boundy.s) {
        // cout << "!!!!!!!\n";
        continue;
      }
      // if (m.find(newloc) == m.end()) { // not claiemd yet
      if (m[newloc.f + OFFSET][newloc.s + OFFSET] == -1) {
        q.push(newloc);
        // m[newloc] = type;
        m[newloc.f + OFFSET][newloc.s + OFFSET] = type;
        if (!type) mcnt++;
      }
    }
  } 
}

void solve() {
  memset(m, -1, sizeof m);
  cin >> xg >> yg >> xm >> ym;

  // int buf = 2 * (abs(xg - xm) + abs(yg - ym)) / 5 + 10;
  int buf = (abs(xg - xm) + abs(yg - ym)) + 10;
  pair<int, int> boundx = mp(max(-OFFSET, min(xg,xm)-buf), min(OFFSET, max(xg,xm)+buf));
  pair<int, int> boundy = mp(max(-OFFSET, min(yg,ym)-buf), min(OFFSET, max(yg,ym)+buf));

  // unordered_map<pair<int,int>, bool, pair_hash> m;
  // 0 is M
  // 1 is G

  // m[mp(xm, ym)] = 0;
  // m[mp(xg, yg)] = 1;

  m[xm + OFFSET][ym + OFFSET] = 0;
  m[xg + OFFSET][yg + OFFSET] = 1;

  int mcnt = 0;

  queue<pair<int, int>> qm, qg;


  qm.push(mp(xm, ym));
  qg.push(mp(xg, yg));

  int gexp= 1, mexp = 1; // each keeps count of how many times theyve expanded

  while(!qm.empty()) {
    // cout << qm.front().f << " " << qm.front().s;
    if (2 * gexp <= 7 * mexp) step(m, qg, 1, gexp, mcnt, boundx, boundy); // grass exp
    else  step(m, qm, 0, mexp, mcnt, boundx, boundy); // myc exp
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
