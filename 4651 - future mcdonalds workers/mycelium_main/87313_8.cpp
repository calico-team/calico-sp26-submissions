#include <bits/stdc++.h>
using namespace std;

#define int long long
#define has(x, y) x.find(y) != x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define YESNO(x) cout << (x) ? "YES" : "NO" << endl;
#define DEBUG_MODE true
#define DEBUG if (DEBUG_MODE)
#define NOTDEBUG if (!DEBUG_MODE)

using ld = long double;
using pi = pair<int, int>;
using graph = vector<vector<int>>;

const int SIZE = 2e5 + 5;
const int INF = 1e15;

void solve() {
  int xg, yg, xm, ym; cin >> xg >> yg >> xm >> ym;

  //offset the neg coords bc bonus 1 is -200 to +200
  xg += 200; yg += 200; xm += 200; ym += 200;

  const int MAX = 1200; //maximum coordinate: 400(200+200)+800 (max spread in 1k ticks)
  vector<vector<int>> clm(MAX, vector<int>(MAX, 0)); //stores which claimed this tile first {0=empty, 1=grass, 2=mycelium}

  //initial claims of mycelium and grass (at t=0)
  clm[xg][yg] = 1; //grass init
  clm[xm][ym] = 2; //mycelium init

  //create boundaries for the bfs expansion for 1 and 2
  vector<pi> g_bound, m_bound;
  g_bound.pb({xg, yg});
  m_bound.pb({xm, ym});

  int t = 0; //tick counter

  //sim loop where we go until there is no more claimable tiles
  while ((!g_bound.empty()||!m_bound.empty())) {
    t++;

    if (t%2==0&&!g_bound.empty()) {
      vector<pi> new_g;
      int dx[] = {1, -1, 0, 0};
      int dy[] = {0, 0, 1, -1};
      for (auto [x, y] : g_bound) {
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];
          if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX) {
            if (clm[nx][ny] == 0) {
              clm[nx][ny] = 1;
              new_g.push_back({nx, ny});
            }
          }
        }
      }
      g_bound = new_g;
    }
    
    if (t%7==0&&!m_bound.empty()) {
      vector<pi> new_m;
      int dx[] = {1, -1, 0, 0};
      int dy[] = {0, 0, 1, -1};
      for (auto [x, y]:m_bound) {
        for (int d=0; d<4; d++) {
          int nx = x+dx[d];
          int ny = y+dy[d];
          if (nx>=0&&nx<MAX&&ny>=0&&ny<MAX) {
            if (clm[nx][ny]==0) {
              clm[nx][ny] = 2;
              new_m.pb({nx, ny});
            }
          }
        }
      }
      m_bound = new_m;
    }
  }
  int cnt = 0; //count how many tiles have mycellium (2 state)
  for (int i =0; i<MAX; i++) {
    for (int j=0; j<MAX; j++) {
      cnt+=clm[i][j]==2; //check if tile is mycellium
    }
  }
  cout<<cnt<<'\n';
}

signed main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}