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

int summin(const string& a, const string& b) {
  int reta = 0, retb = 0;
  for(int i = 0; i < sz(a); i++) {
    reta += a[i] == '#';
    retb += b[i] == '#';
  }
  return max(reta, retb);
}
int summax(const string& a, const string& b) {
  int reta = 0, retb = 0;
  for(int i = 0; i < sz(a); i++) {
    reta += a[i] == '#';
    retb += b[i] == '#';
  }
  return reta * retb;
}

void rsolve() {
  int n;
  cin >> n;
  vector<string> ga(n), gb(n);
  for(int i = 0; i < n; i++) cin >> ga[i];
  for(int i = 0; i < n; i++) cin >> gb[i];
  ll lhs = 0, rhs = 0;
  for(int i = 0; i < n; i++) {
    lhs += summin(ga[i], gb[i]);
    rhs += summax(ga[i], gb[i]);
  }
  cout << rhs << " " << lhs << "\n";
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