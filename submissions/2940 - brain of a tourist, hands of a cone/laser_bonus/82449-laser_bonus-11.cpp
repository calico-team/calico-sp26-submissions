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

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}
ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
  if((a-b)%g) return -1;
	assert((a - b) % g == 0); // else no solution
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

int prop(vector<int>& v, int src, int inc, int sz) {
  v.assign(sz, -1);
  int period = 0;
  int curr = src;
  while(v[curr] == -1) {
    v[curr] = period++;
    curr += inc;
    curr %= sz;
  }
  return period;
}
void rsolve() {
  ll k, n, m, p, q;
  cin >> k >> n >> m >> p >> q;
  vector<array<int, 2>> v(k);
  map<array<int, 2>, int> dp;
  vector<int> xseen(n, -1), yseen(m, -1);
  for(int i = 0; i < k; i++) {
    cin >> v[i][0] >> v[i][1];
    dp[v[i]] = i;
  }
  ll xperiod = prop(xseen, v[0][0], q, n);
  ll yperiod = prop(yseen, v[0][1], p, m);
  ll firstat = 1e18;
  ll ret = -1;
  for(int i = 0; i < k; i++) {
    if(xseen[v[i][0]] == -1 || yseen[v[i][1]] == -1) continue;
    ll cand = crt(xseen[v[i][0]], xperiod, yseen[v[i][1]], yperiod);
    if(cand == -1) continue;
    if(cand == 0) cand = (xperiod / gcd(xperiod, yperiod) * yperiod);
    if(updmin(firstat, cand)) ret = i;
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