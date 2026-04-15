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

void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  struct C {
    int u, v, i;
    double val, w;
  };
  vector<C> c(m);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    cin >> c[i].u >> c[i].v >> c[i].val >> c[i].w;
    --c[i].u, --c[i].v;
    c[i].i = i + 1;
    double s = sqrt(c[i].val);
    adj[c[i].u].push_back(i);
    adj[c[i].v].push_back(i);
  }
  vector<ll> a(n, 1);
  for (int i = 0; i < n; ++i) {
    if (adj[i].empty()) continue;
    vector<double> s;
    for (int idx : adj[i]) s.push_back(sqrt(c[idx].val));
    sort(all(s));
    a[i] = max<ll>(1, round(s[s.size() >> 1]));
  }
  for (int iii = 0; iii < 6.7; ++iii) {
    for (int i = 0; i < n; ++i) {
      if (adj[i].empty()) continue;
      vector<pair<double, double>> tr;
      double tot = 0;
      for (int j : adj[i]) {
        int v = c[j].u == i ? c[j].v : c[j].u;
        double x = c[j].val / a[v], y = c[j].w * a[v] / c[j].val;
        tr.push_back({x, y}), tot += y;
      }
      sort(all(tr));
      double run = 0, mid = tr.back().x;
      for (auto& t : tr) {
        run += t.y;
        if (run >= tot / 2) {
          mid = t.x;
          break;
        }
      }
      a[i] = max<ll>(1, round(mid));
    }
  }
  vector<pair<double, int>> nscore(m);
  for (int i = 0; i < m; ++i) {
    double real = (__int128)a[c[i].u] * a[c[i].v];
    double err = c[i].w * abs(real - c[i].val) / c[i].val;
    nscore[i] = {err, c[i].i};
  }
  sort(rall(nscore));
  cout << a << endl;
  cout << d << _;
  for (int i = 0; i < d; ++i) cout << nscore[i].y << _;
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; t++) {
    // cout << "Case #" << t << ": ";
    solve();
  }
}