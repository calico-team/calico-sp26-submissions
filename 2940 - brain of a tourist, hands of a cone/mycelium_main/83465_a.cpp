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
  set<array<int, 2>> gseen, mseen;
  gseen.insert({xg, yg});
  mseen.insert({xm, ym});
  int nt = 1;
  while(true) {
    bool valid = false;
    for(auto [x, y]: mseen) {
      for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(!gseen.count({nx, ny}) && !mseen.count({nx, ny})) {
          valid = true;
          break;
        }
      }
      if(valid) break;
    }
    if(!valid) break;
    while(nt%2 && nt%7) nt++;
    if(nt%2 == 0) {
      set<array<int, 2>> ngseen;
      for(auto [x, y]: gseen) {
        ngseen.insert({x, y});
        for(int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if(mseen.count({nx, ny})) continue;
          ngseen.insert({nx, ny});
        }
      }
      swap(gseen, ngseen);
    }
    if(nt%7 == 0) {
      set<array<int, 2>> nmseen;
      for(auto [x, y]: mseen) {
        nmseen.insert({x, y});
        for(int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if(gseen.count({nx, ny})) continue;
          nmseen.insert({nx, ny});
        }
      }
      swap(mseen, nmseen);
    }
    nt++;
  }
  cout << sz(mseen) << "\n";
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