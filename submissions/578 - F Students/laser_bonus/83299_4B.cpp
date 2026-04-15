#pragma region template
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned long long;
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define sub(a, b, m) (((a % m) - (b % m) + m) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define fi first
#define se second
#define _ ' '
#define endl '\n'

template <class A, class B>
struct Pair {
  A x;
  B y;

  constexpr Pair() : x(), y() {}
  constexpr Pair(const A& a, const B& b) : x(a), y(b) {}

  template <class U1, class U2>
  constexpr Pair(U1&& a, U2&& b)
      : x(std::forward<U1>(a)), y(std::forward<U2>(b)) {}

  template <class U1, class U2>
  constexpr Pair(const Pair<U1, U2>& p) : x(p.x), y(p.y) {}

  template <class U1, class U2>
  constexpr Pair(Pair<U1, U2>&& p)
      : x(std::forward<U1>(p.x)), y(std::forward<U2>(p.y)) {}

  template <class U1, class U2>
  constexpr Pair(const std::pair<U1, U2>& p) : x(p.first), y(p.second) {}

  template <class U1, class U2>
  constexpr Pair(std::pair<U1, U2>&& p)
      : x(std::forward<U1>(p.first)), y(std::forward<U2>(p.second)) {}

  constexpr Pair(const Pair&) = default;
  constexpr Pair(Pair&&) = default;
  constexpr Pair& operator=(const Pair&) = default;
  constexpr Pair& operator=(Pair&&) = default;

  template <class U1, class U2>
  constexpr Pair& operator=(const std::pair<U1, U2>& p) {
    x = p.first;
    y = p.second;
    return *this;
  }

  template <class U1, class U2>
  constexpr Pair& operator=(std::pair<U1, U2>&& p) {
    x = std::forward<U1>(p.first);
    y = std::forward<U2>(p.second);
    return *this;
  }

  constexpr operator std::pair<A, B>() const { return {x, y}; }

  constexpr void swap(Pair& other) noexcept(noexcept(std::swap(x, other.x)) &&
                                            noexcept(std::swap(y, other.y))) {
    using std::swap;
    swap(x, other.x);
    swap(y, other.y);
  }

  friend constexpr bool operator==(const Pair& a, const Pair& b) {
    return a.x == b.x && a.y == b.y;
  }
  friend constexpr bool operator!=(const Pair& a, const Pair& b) {
    return !(a == b);
  }
  friend constexpr bool operator<(const Pair& a, const Pair& b) {
    return (a.x < b.x) || (!(b.x < a.x) && a.y < b.y);
  }
  friend constexpr bool operator>(const Pair& a, const Pair& b) {
    return b < a;
  }
  friend constexpr bool operator<=(const Pair& a, const Pair& b) {
    return !(b < a);
  }
  friend constexpr bool operator>=(const Pair& a, const Pair& b) {
    return !(a < b);
  }
};

template <class A, class B>
Pair(A, B) -> Pair<A, B>;

template <std::size_t I, class A, class B>
constexpr auto& get(Pair<A, B>& p) noexcept {
  static_assert(I < 2);
  if constexpr (I == 0)
    return p.x;
  else
    return p.y;
}

template <std::size_t I, class A, class B>
constexpr const auto& get(const Pair<A, B>& p) noexcept {
  static_assert(I < 2);
  if constexpr (I == 0)
    return p.x;
  else
    return p.y;
}

template <std::size_t I, class A, class B>
constexpr auto&& get(Pair<A, B>&& p) noexcept {
  static_assert(I < 2);
  if constexpr (I == 0)
    return std::move(p.x);
  else
    return std::move(p.y);
}

template <std::size_t I, class A, class B>
constexpr const auto&& get(const Pair<A, B>&& p) noexcept {
  static_assert(I < 2);
  if constexpr (I == 0)
    return std::move(p.x);
  else
    return std::move(p.y);
}

namespace std {
template <class A, class B>
struct tuple_size<Pair<A, B>> : integral_constant<size_t, 2> {};

template <class A, class B>
struct tuple_element<0, Pair<A, B>> {
  using type = A;
};

template <class A, class B>
struct tuple_element<1, Pair<A, B>> {
  using type = B;
};

template <class A, class B>
struct hash<Pair<A, B>> {
  size_t operator()(const Pair<A, B>& p) const {
    size_t h1 = std::hash<A>{}(p.x);
    size_t h2 = std::hash<B>{}(p.y);
    return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
  }
};
};  // namespace std

#define pair Pair

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

pair<int, int> dir[]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
pair<int, int> diag[]{
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1},
};

template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (T& x : v) in >> x;
  return in;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  for (const T& x : v) out << x << ' ';
  return out;
}

#ifdef LOCAL
#include "../tools/debug.h"
#else
#define DBG(...)
#define CHK(...)
#endif

#pragma endregion template

constexpr int MOD = 998244353, N = 2e5 + 67;

#define int ll

int gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
int modinv(int b, int m) {
  int x, y;
  int g = gcd(b, m, x, y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}

void solve() {
  int k, n, m, p, q;
  cin >> k >> n >> m >> p >> q;
  vector<pair<int, int>> a(k);
  for (auto& x : a) cin >> x.x >> x.y;
  auto& s = a.front();
  pair<int, int> b = {gcd(q, n), gcd(p, m)};
  pair<int, int> c = {n / b.x, m / b.y};
  int best = LLONG_MAX, besti = -1;
  for (int i = 0; i < k; ++i) {
    DBG(i);
    auto& [x, y] = a[i];
    int dx = sub(x, s.x, n), dy = sub(y, s.y, m);
    if (dx % b.x != 0 || dy % b.y != 0) continue;
    // z = za mod c.x
    //     zb mod c.y
    pair<int, int> inv = {modinv(q / b.x, c.x), modinv(p / b.y, c.y)};
    int za = ((dx / b.x) * inv.x) % c.x, zb = ((dy / b.y) * inv.y) % c.y;
    DBG(x, y, za, zb);
    int u, v;
    // c.x*u+c.y*v=zb-za
    int g = gcd(c.x, c.y, u, v);
    int sb = zb - za;
    if (sb % g != 0) continue;
    int lcm = c.x / g * c.y;
    DBG(g, sb, lcm);
    // sol
    int M = c.y / g;
    u %= M;
    int mm = (u * ((sb / g) % M)) % M;
    if (mm < 0) mm += M;
    int z = (za + c.x * mm) % lcm;
    CHK(z == 0, lcm, true);
    if (z == 0) z = lcm;
    DBG(z);
    if (z < best) best = z, besti = i;
  }
  CHK(besti > -1);
  cout << besti << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    // cout << "Case #" << t << ": ";
    solve();
  }
}