/*

t p = x mod n
t q = y mod m

t = pI x mod n
t = qI y mod m

if there is no pI mod n then ... p shares factors with n

*/

#include <bits/stdc++.h>

namespace kactl {
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Unknown
 * Date: 2002-09-15
 * Source: predates tinyKACTL
 * Description: Finds two integers $x$ and $y$, such that $ax+by=\gcd(a,b)$. If
 * you just need gcd, use the built in \texttt{\_\_gcd} instead.
 * If $a$ and $b$ are coprime, then $x$ is the inverse of $a \pmod{b}$.
 */
ll euclid(ll a, ll b, ll &x, ll &y) {
  if (!b) return x = 1, y = 0, a;
  ll d = euclid(b, a % b, y, x);
  return y -= a / b * x, d;
}

/**
 * Author: Simon Lindholm
 * Date: 2019-05-22
 * License: CC0
 * Description: Chinese Remainder Theorem.
 *
 * \texttt{crt(a, m, b, n)} computes $x$ such that $x\equiv a \pmod m$, $x\equiv
 * b \pmod n$. If $|a| < m$ and $|b| < n$, $x$ will obey $0 \le x <
 * \text{lcm}(m, n)$. Assumes $mn < 2^{62}$. Time: $\log(n)$ Status: Works
 */

ll crt(ll a, ll m, ll b, ll n) {
  if (n > m) swap(a, b), swap(m, n);
  ll x, y, g = euclid(m, n, x, y);
  if ((a - b) % g == 0) {  // else no solution
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x;
  } else {
    return -1;
  }
}

/**
 * Author: Lukas Polacek
 * Date: 2009-09-28
 * License: CC0
 * Source: folklore
 * Description: Operators for modular arithmetic. You need to set {\tt mod} to
 * some number first and then you can use the structure.
 */

ll invert(ll a, ll m) {  // find a^-1 mod m
  ll x, y, g = euclid(a, m, x, y);
  assert(g == 1);
  return ((x % m) + m) % m;
}

}  // namespace kactl

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<vi> v2i;
typedef std::vector<v2i> v3i;
typedef std::vector<ll> vll;
#define va(type, sz) std::vector<std::array<type, sz>>
#define v2a(type, sz) std::vector<va(type, sz)>
#define setmax(a, b) a = std::max(a, b)
#define setmin(a, b) a = std::min(a, b)

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

  int tn = 1;
  std::cin >> tn;
  std::cerr << "\e[1;31m\e[5m[!]\e[25m MULTITEST MODE \e[5m[!]\e[25m\e[0m"
            << std::endl;
  while (tn--) {
    ll k, n, m, p, q;  // k n m p q
    std::cin >> k >> n >> m >> q >> p; // wtf swapped why
    va(ll, 2) a(k);
    for (auto &r : a)
      for (auto &x : r) std::cin >> x;
    auto b = a;

    auto [x0, y0] = a[0];
    for (auto &[x, y] : a) {
      x -= x0;
      y -= y0;
      // std::cout << x << " " << y << "\n";
    }
    if (std::gcd(p, n) != 1) {
      int g = std::gcd(p, n);
      p /= g;
      n /= g;
      for (auto &[x, y] : a) {
        if (x % g)
          x = -n;
        else
          x /= g;
      }
    }
    if (std::gcd(q, m) != 1) {
      int g = std::gcd(q, m);
      q /= g;
      m /= g;
      for (auto &[x, y] : a) {
        if (y % g)
          y = -m;
        else
          y /= g;
      }
    }
    ll pi = kactl::invert(p, n);
    ll qi = kactl::invert(q, m);

    int ans = 0;
    ll ht = 1e18;
    // std::cout << "xy=(" << x0 << " " << y0 << ")\n";
    // std::cout << "dxy=(" << p << " " << q << ")\n";
    for (int i = 1; i < k; ++i) {
      auto [x, y] = a[i];
      // std::cout << "hit" << i << "(" << b[i][0] << " " << b[i][1] << ")" << "\n";
      if (x == -n || y == -m) continue;
      ll t = kactl::crt((pi * x) % n, n, (qi * y) % m, m);
      // std::cout << "hit" << i << "(" << x+x0 << " " << y+y0 << ")" << "at t=" << t << "\n";
      if (t > 0 && t < ht) {
        ht = t;
        ans = i;
      }
    }
    std::cout << ans;

    std::cout << std::endl;
  }
  return 0;
}