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

constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}
// @param n `n < 2^32`
// @param m `1 <= m < 2^32`
// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)
unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        // y_max < m * (n + 1)
        // floor(y_max / m) <= n
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}
long long floor_sum(long long n, long long m, long long a, long long b) {
    assert(0 <= n && n < (1LL << 32));
    assert(1 <= m && m < (1LL << 32));
    unsigned long long ans = 0;
    if (a < 0) {
        unsigned long long a2 = safe_mod(a, m);
        ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);
        a = a2;
    }
    if (b < 0) {
        unsigned long long b2 = safe_mod(b, m);
        ans -= 1ULL * n * ((b2 - b) / m);
        b = b2;
    }
    return ans + floor_sum_unsigned(n, m, a, b);
}

void rsolve() {
  ll xg, yg, xm, ym;
  cin >> xg >> yg >> xm >> ym;
  ll srcx = abs(xg - xm);
  ll srcy = abs(yg - ym);
  if(srcx < srcy) swap(srcx, srcy);
  if(srcx == 2 && srcy == 0) return void(cout << "2\n");
  ll xlo = srcx, xhi = srcx;
  ll ylo = srcy, yhi = srcy;
  auto dist7 = [&](ll x, ll y) -> ll {
    return 7 * (abs(x-srcx) + abs(y-srcy));
  };
  auto disttopcand = [&](ll x, ll y) -> ll {
    assert(x >= srcx && y >= srcy);
    ll topcand = abs(srcx) + abs(yhi+1);
    topcand += abs(x-srcx) + abs((yhi+1)-y);
    return topcand;
  };
  auto distbotcand = [&](ll x, ll y) -> ll {
    assert(x >= srcx && y >= srcy);
    ll botcand = abs(srcx) + abs((ylo-1));
    botcand += abs(srcx - (xhi+1)) + abs((ylo-1)-srcy);
    botcand += abs((xhi+1)-x) + abs(srcy - y);
    return botcand;
  };
  auto dist = [&](ll x, ll y) -> ll {
    ll ret = abs(x) + abs(y);
    if(x > srcx) {
      if(y <= srcy) {
        ret = abs(srcx) + abs((ylo-1));
        ret += abs(srcx - x) + abs((ylo-1) - y);
      }
      else {
        assert(y > srcy);
        ret = min(disttopcand(x, y), distbotcand(x, y));
      }
    }
    return ret;
  };
  {
    ll lx = 0;
    ll rx = srcx;
    while(lx < rx) {
      ll mid = (lx+rx)/2;
      if(dist(mid, srcy) * 2 <= dist7(mid, srcy)) lx = mid+1;
      else rx = mid;
    }
    assert(lx == rx);
    xlo = lx;
  }
  {
    ll ly = -3e9;
    ll ry = srcy;
    while(ly < ry) {
      ll mid = ly + (ry - ly) / 2;
      if(dist(srcx, mid) * 2 <= dist7(srcx, mid)) ly = mid+1;
      else ry = mid;
    }
    ylo = ly;
  }
  {
    ll ly = srcy;
    ll ry = 3e9;
    while(ly < ry) {
      ll mid = ly + (ry - ly + 1) / 2;
      if(dist(srcx, mid) * 2 <= dist7(srcx, mid)) ry = mid-1;
      else ly = mid;
    }
    yhi = ly;
  }
  {
    ll lx = srcx;
    ll rx = 3e9;
    while(lx < rx) {
      ll mid = (lx+rx+1)/2;
      if(dist(mid, srcy) * 2 <= dist7(mid, srcy)) rx = mid-1;
      else lx = mid;
    }
    assert(lx == rx);
    xhi = lx;
  }
  ll ret = 0;
  debug(xlo, xhi, ylo, yhi);
  if(ylo >= 0) {
    // x < srcx, ylo >= 0
    ret += (srcx-xlo)*(srcx-xlo-1)/2;
  }
  else {
    // x < srcx, ylo < 0
    ll nxlo = srcy + 1 + xlo;
    ret += srcy * (srcy+1) / 2;
    ret += srcy * (srcx-nxlo);
    nxlo--;
    ret += floor_sum(srcx-nxlo, 5, 9, -1-7*srcx-7*srcy+9*nxlo);
    if(false) {
      for(int i = nxlo; i <= srcx-1; i++) {
        for(int j = ylo; j <= -1; j++) {
          if(dist(i, j) * 2 > dist7(i, j)) ret++;
        }
      }
    }
  }
  // x < srcx, y > srcy
  {
    ret += floor_sum(srcx-xlo, 5, 9, -7*srcx+7*srcy-1+9*xlo);
    ret -= srcy * (srcx - xlo);
  }
  // x > srcx, y < srcy
  {
    ret += floor_sum(xhi-srcx, 9, -5, 2*(-srcx-ylo+1+srcx+abs(ylo-1)) - 1 + 7*srcx-7*srcy-5*(srcx+1));
    ret += srcy * (xhi - srcx);
  }
  // x > srcx, y > srcy
  {
    ll xl = srcx+1;
    ll xr = xhi;
    while(xl < xr) {
      ll xmid = (xl + xr) / 2;
      ll yl = srcy+1;
      ll yr = yhi+1;
      while(yl < yr) {
        ll ymid = (yl+yr)/2;
        if(dist(xmid, ymid) * 2 > dist7(xmid, ymid)) yl = ymid+1;
        else yr = ymid;
      }
      // (xmid, yl) is purple
      yl--; 
      if(disttopcand(xmid, yl) < distbotcand(xmid, yl)) {
        xl = xmid+1;
      }
      else {
        xr = xmid;
      }
    }
    int xthresh = xl - 1;
    // x > srcx, top candidate path
    ret += floor_sum(xthresh - srcx, 9, -5, 2*(srcx+yhi+1-srcx+yhi+1)-1+7*srcx+7*srcy-5*(srcx+1));
    ret -= srcy*(xthresh-srcx);
    if(false) {
      for(int i = srcx+1; i <= xthresh; i++) {
        for(int j = srcy+1; j <= yhi; j++) {
          if(disttopcand(i, j) * 2 > dist7(i, j)) ret++;
        }
      }
    }
    ll yl = srcy+1;
    ll yr = yhi+1;
    while(yl < yr) {
      ll ymid = (yl+yr)/2;
      if(dist(xthresh+1, ymid) * 2 > dist7(xthresh+1, ymid)) yl = ymid+1;
      else yr = ymid;
    }
    // (xmid, yl) is purple
    yl--; 
    // x > src, bot candidate path
    ret += floor_sum(xhi - xthresh, 5, -9, 2*(srcx+abs(ylo-1)+xhi+1-srcx+srcy-ylo+1+xhi+1-srcy)-1+7*srcx+7*srcy-9*(xthresh+1));
    ret -= srcy*(xhi-xthresh);
    for(int i = xthresh+1; i <= xthresh+10 && i <= xhi; i++) {
      for(int j = yl+1; j <= yl+10 && j <= yhi; j++) {
        if(distbotcand(i, j) * 2 > dist7(i, j)) ret--;
      }
    }
  }
  ret += (xhi - xlo + 1);
  ret += (yhi - ylo + 1);
  ret--;
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