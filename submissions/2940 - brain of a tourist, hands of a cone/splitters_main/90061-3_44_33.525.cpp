#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// thanks gena
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 67
#endif
// END NO SAD

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
#define derr if(1) cerr

template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template<class T>
bool updmin(T& a, T b) {
  if(b < a) {
    a = b;
    return true;
  }
  return false;
}
template<class T>
bool updmax(T& a, T b) {
  if(b > a) {
    a = b;
    return true;
  }
  return false;
}
typedef int64_t ll;

typedef array<ll, 2> frac;
void reduce(frac& f) {
  ll g = gcd(f[0], f[1]);
  f[0] /= g;
  f[1] /= g;
}
frac add(frac a, frac b) {
  frac ret;
  ret[0] = a[0] * b[1] + a[1] * b[0];
  ret[1] = a[1] * b[1];
  reduce(ret);
  return ret;
}

void rsolve() {
  int r, c;
  cin >> r >> c;
  vector<string> g(r);
  for(auto& x: g) cin >> x;
  frac ret; ret[0] = 0; ret[1] = 1;
  vector<vector<int>> par(r);
  for(auto& x: par) x.resize(c);
  vector<vector<int>> denom(r);
  for(auto& x: denom) x.resize(c);
  for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) {
    if(g[i][j] == '.') continue;
    if(g[i][j] == 'X') continue;
    if(g[i][j] == '^') {
      if(i > 0) par[i-1][j]++;
      continue;
    }
    if(g[i][j] == 'v') {
      if(i+1 < r) par[i+1][j]++;
      continue;
    }
    if(g[i][j] == '<') {
      if(j > 0) par[i][j-1]++;
      continue;
    }
    if(g[i][j] == '>') {
      if(j < c) par[i][j+1]++;
      continue;
    }
    assert(g[i][j] == 'S');
    if(i && g[i-1][j] != 'v' && g[i-1][j] != '.') par[i-1][j]++, denom[i][j]++;
    if(i+1<r && g[i+1][j] != '^' && g[i+1][j] != '.') par[i+1][j]++, denom[i][j]++;
    if(j && g[i][j-1] != '>'  && g[i][j-1] != '.') par[i][j-1]++, denom[i][j]++;
    if(j+1<c && g[i][j+1] != '<' && g[i][j+1] != '.') par[i][j+1]++, denom[i][j]++;
  }
  queue<array<int, 2>> q;
  q.push({0, 0});
  vector<vector<frac>> dp(r);
  for(auto& x: dp) x.assign(c, frac({0, 1}));
  dp[0][0] = frac({1, 1});
  while(sz(q)) {
    auto [x, y] = q.front(); q.pop();
    debug(x, y, dp[x][y]);
    assert(g[x][y] != '.');
    if(g[x][y] == 'X') {
      debug("ACTUAL LOSS", dp[x][y]);
      ret = add(ret, dp[x][y]);
      continue;
    }
    if(g[x][y] == '^') {
      if(x == 0) continue;
      dp[x-1][y] = add(dp[x-1][y], dp[x][y]);
      if(--par[x-1][y] == 0) q.push({x-1, y});
      continue;
    }
    if(g[x][y] == 'v') {
      if(x+1 == r) continue;
      dp[x+1][y] = add(dp[x+1][y], dp[x][y]);
      if(--par[x+1][y] == 0) q.push({x+1, y});
      continue;
    }
    if(g[x][y] == '<') {
      if(y == 0) continue;
      dp[x][y-1] = add(dp[x][y-1], dp[x][y]);
      if(--par[x][y-1] == 0) q.push({x, y-1});
      continue;
    }
    if(g[x][y] == '>') {
      if(y + 1 == c) continue;
      dp[x][y+1] = add(dp[x][y+1], dp[x][y]);
      if(--par[x][y+1] == 0) q.push({x, y+1});
      continue;
    }
    assert(g[x][y] == 'S');
    frac inc = dp[x][y];
    inc[1] *= denom[x][y];
    if(x && g[x-1][y] != 'v') {
      dp[x-1][y] = add(dp[x-1][y], inc);
      if(--par[x-1][y] == 0) q.push({x-1, y});
    }
    if(x+1<r && g[x+1][y] != '^') {
      dp[x+1][y] = add(dp[x+1][y], inc);
      if(--par[x+1][y] == 0) q.push({x+1, y});
    }
    if(y && g[x][y-1] != '>') {
      dp[x][y-1] = add(dp[x][y-1], inc);
      if(--par[x][y-1] == 0) q.push({x, y-1});
    }
    if(y+1<c && g[x][y+1] != '<') {
      dp[x][y+1] = add(dp[x][y+1], inc);
      if(--par[x][y+1] == 0) q.push({x, y+1});
    }
  }
  ret[0] = ret[1] - ret[0];
  cout << ret[0] << " " << ret[1] << "\n";
}

void solve() {
  int t = 1;
  cin >> t;
  while(t--) rsolve();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}