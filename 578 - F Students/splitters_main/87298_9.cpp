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

using lol = __int128;
lol gcd128(lol a, lol b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

struct Frac {
  lol p, q;
  Frac(lol _p = 0, lol _q = 1) {
    if (_q < 0) {
      _p = -_p;
      _q = -_q;
    }
    lol g = gcd((_p < 0 ? -_p : _p), _q);
    if (g == 0) {
      p = 0;
      q = 1;
    } else {
      p = _p / g;
      q = _q / g;
    }
  }
  Frac operator+(const Frac& o) const {
    lol g = gcd(q, o.q);
    lol num = p * (o.q / g) + o.p * (q / g);
    lol den = (q / g) * o.q;
    return Frac(num, den);
  }
  Frac operator*(const Frac& o) const { return Frac(p * o.p, q * o.q); }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector a(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      a[i][j] = s[j];
    }
  }
  struct State {
    ll x, y;
    Frac f;
  };
  queue<State> q;
  q.push({0, 0, {1, 1}});
  Frac coll = {0, 1}, dest = {0, 1};
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    if (u.y >= n || u.x >= m || u.y < 0 || u.x < 0) {
      coll = coll + u.f;
      continue;
    }
    char c = a[u.y][u.x];
    if (c == '>') {
      q.push({u.x + 1, u.y, u.f});
    } else if (c == '<') {
      q.push({u.x - 1, u.y, u.f});
    } else if (c == '^') {
      q.push({u.x, u.y - 1, u.f});
    } else if (c == 'v') {
      q.push({u.x, u.y + 1, u.f});
    } else if (c == '.') {
      continue;
    } else if (c == 'X') {
      dest = dest + u.f;
    } else if (c == 'S') {
      ll x = u.x, y = u.y;
      vector<pair<int, int>> adj;
      if (y - 1 >= 0) {
        char t = a[y - 1][x];
        if (t == 'X' || t == '<' || t == '>' || t == '^')
          adj.push_back({x, y - 1});
      }
      if (y + 1 < n) {
        char t = a[y + 1][x];
        if (t == 'X' || t == '<' || t == '>' || t == 'v')
          adj.push_back({x, y + 1});
      }
      if (x - 1 >= 0) {
        char t = a[y][x - 1];
        if (t == 'X' || t == '<' || t == '^' || t == 'v')
          adj.push_back({x - 1, y});
      }
      if (x + 1 < m) {
        char t = a[y][x + 1];
        if (t == 'X' || t == '>' || t == '^' || t == 'v')
          adj.push_back({x + 1, y});
      }
      Frac f = u.f * Frac(1, adj.size());
      for (auto p : adj) q.push({p.x, p.y, f});
    }
  }
  Frac top = coll;
  Frac bottom = coll + dest;
  __int128 x = (__int128)top.p * bottom.q;
  __int128 y = (__int128)top.q * bottom.p;
  ll g = gcd(x, y);
  x /= g, y /= g;
  cout << (ll)x << _ << (ll)y << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    // cout << "Case #" << t << ": ";
    solve();
  }
}