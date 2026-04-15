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

void fast(vector<ll>& ret, const vector<ll>& v) {
  if(sz(v) < 3) {
    ret = v;
    return;
  }
  int n = sz(v);
  ret.resize(n);
  for(int i = 0; i < n; i++) {
    if(i == 0 || i == n-1) ret[i] = v[i];
    else {
      ll curr = v[i-1] + v[i] + v[i+1];
      curr -= min(v[i-1], min(v[i], v[i+1]));
      curr -= max(v[i-1], max(v[i], v[i+1]));
      ret[i] = curr;
    }
  }
}
ll score(const vector<ll>& a, const vector<ll>& b) {
  assert(sz(a) == sz(b));
  int n = sz(a);
  ll ret = 0;
  for(int i = 0; i < n; i++) ret += abs(a[i] - b[i]);
  for(int i = 0; i + 1 < n; i++) {
    ret += abs(a[i] - a[i+1]);
    ret += abs(b[i] - b[i+1]);
  }
  return ret;
}
void slow(vector<ll>& ret, const vector<ll>& v) {
  int n = sz(v);
  ret.resize(n);
  ll lhs = *min_element(all(v));
  ll rhs = *max_element(all(v));
  ll cost = 1e18;
  vector<ll> cand(sz(v));
  auto dfs = y_combinator([&](auto self, int idx) -> void {
    if(idx == n) {
      if(updmin(cost, score(ret, v))) {
        ret = cand;
      }
      return;
    }
    for(int i = lhs; i <= rhs; i++) {
      cand[idx] = i;
      self(idx+1);
    }
  });
}
void rsolve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for(auto& x: v) cin >> x;
  vector<ll> ret;
  fast(ret, v);
  for(int i = 0; i < n; i++) {
    cout << ret[i] << " \n"[i == n-1];
  }
  if(false) {
    ll cost = score(v, ret);
    debug(ret);
    slow(ret, v);
    ll cost2 = score(v, ret);
    debug(ret);
    assert(cost == cost2);
  }
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