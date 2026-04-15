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

int dx[4]{-1,0,1,0};
int dy[4]{0,1,0,-1};

void rsolve() {
  int xg, yg, xm, ym;
  cin >> xg >> yg >> xm >> ym;
  int srcx = abs(xg - xm);
  int srcy = abs(yg - ym);
  if(srcx < srcy) swap(srcx, srcy);
  int xlo = srcx, xhi = srcx;
  int ylo = srcy, yhi = srcy;
  auto dist7 = [&](int x, int y) -> int {
    return 7 * (abs(x-srcx) + abs(y-srcy));
  };
  auto dist = [&](int x, int y) -> int {
    int ret = abs(x) + abs(y);
    if(x > srcx) {
      if(y <= srcy) {
        ret = abs(srcx) + abs((ylo-1));
        ret += abs(srcx - x) + abs((ylo-1) - y);
      }
      else {
        assert(y > srcy);
        int topcand = abs(srcx) + abs(yhi+1);
        topcand += abs(x-srcx) + abs((yhi+1)-y);
        int botcand = abs(srcx) + abs((ylo-1));
        botcand += abs(srcx - (xhi+1)) + abs((ylo-1)-srcy);
        botcand += abs((xhi+1)-x) + abs(srcy - y);
        ret = min(topcand, botcand);
      }
    }
    return ret;
  };
  {
    int lx = 0;
    int rx = srcx;
    while(lx < rx) {
      int mid = (lx+rx)/2;
      if(dist(mid, srcy) * 2 <= dist7(mid, srcy)) lx = mid+1;
      else rx = mid;
    }
    assert(lx == rx);
    xlo = lx;
  }
  {
    int ly = -1e6;
    int ry = srcy;
    while(ly < ry) {
      int mid = ly + (ry - ly) / 2;
      if(dist(srcx, mid) * 2 <= dist7(srcx, mid)) ly = mid+1;
      else ry = mid;
    }
    ylo = ly;
  }
  {
    int ly = srcy;
    int ry = 1e6;
    while(ly < ry) {
      int mid = ly + (ry - ly + 1) / 2;
      if(dist(srcx, mid) * 2 <= dist7(srcx, mid)) ry = mid-1;
      else ly = mid;
    }
    yhi = ly;
  }
  {
    int lx = srcx;
    int rx = 1e6;
    while(lx < rx) {
      int mid = (lx+rx+1)/2;
      if(dist(mid, srcy) * 2 <= dist7(mid, srcy)) rx = mid-1;
      else lx = mid;
    }
    assert(lx == rx);
    xhi = lx;
  }
  int ret = 0;
  debug(xlo, xhi, ylo, yhi);
  for(int i = xlo; i <= xhi; i++) for(int j = ylo; j <= yhi; j++) {
    if(dist(i, j) * 2 > dist7(i, j)) {
      debug(i, j);
      ret++;
    }
  }
  cout << ret << "\n";
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