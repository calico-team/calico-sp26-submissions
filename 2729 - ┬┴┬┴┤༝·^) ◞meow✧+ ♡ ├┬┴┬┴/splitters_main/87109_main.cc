/*

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
 * Date: 2002-09-13
 * Source: predates tinyKACTL
 * Description: Topological sorting. Given is an oriented graph.
 * Output is an ordering of vertices, such that there are edges only from left
 * to right. If there are cycles, the returned list will have size smaller than
 * $n$ -- nodes reachable from cycles will not be returned. Time: $O(|V|+|E|)$
 * Status: stress-tested
 */
vi topoSort(const vector<vi>& gr) {
  vi indeg(sz(gr)), q;
  for (auto& li : gr)
    for (int x : li) indeg[x]++;
  rep(i, 0, sz(gr)) if (indeg[i] == 0) q.push_back(i);
  rep(j, 0, sz(q)) for (int x : gr[q[j]]) if (--indeg[x] == 0) q.push_back(x);
  return q;
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
    ll n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (auto& x : a) std::cin >> x;

#define K(i, j) (i * m + j)

    v2i adj(n * m + 1);
    auto AddEdge = [&](int i, int j, int i2, int j2) -> void {
      if (i < 0 || i >= n || j < 0 || j >= m) return;
      if (i2 < 0 || i2 >= n || j2 < 0 || j2 >= m) return;
      // std::cout << i << " " << j << " ->" << i2 << " " << j2 << std::endl;
      adj[K(i, j)].push_back(K(i2, j2));
    };
    auto Next = [&](int i, int j) -> std::array<int, 2> {
      if (a[i][j] == '>') return {i, j + 1};
      if (a[i][j] == '<') return {i, j - 1};
      if (a[i][j] == 'v') return {i + 1, j};
      if (a[i][j] == '^') return {i - 1, j};
      return {-1, -1};
    };
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        // push
        auto [ni, nj] = Next(i, j);
        if (ni >= 0) AddEdge(i, j, ni, nj);
        if (a[i][j] == 'S') {
          for (auto [di, dj] :
               va(int, 2){/*adj */ {0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
            int ni = i + di, nj = j + dj;
            // valid coordinates: i in [0,n), j in [0,m)
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (Next(ni, nj) == std::array<int, 2>{i, j}) continue;
            if (a[ni][nj] != '.') AddEdge(i, j, ni, nj);
          }
        }
      }
    }
    // for (auto x : adj) {
    //   for (auto y : x) std::cout << y << " ";
    //   std::cout << std::endl;
    // }

    va(ll, 2) tot(n * m + 1, {0, 1});
    tot[K(0, 0)] = {1, 1};
    for (int i = 0; i < m; ++i) {
      if (a[0][i] == '^') adj[K(0, i)].push_back(n * m);
    }
    vi order = kactl::topoSort(adj);
    // std::reverse(order.begin(), order.end());
    for (auto i : order) {
      // push
      auto [p, q] = tot[i];
      q *= adj[i].size();

      for (auto j : adj[i]) {
        auto [p2, q2] = tot[j];
        ll np = p * q2 + p2 * q;
        ll nq = q * q2;
        ll g = std::gcd(np, nq);
        tot[j] = {np / g, nq / g};
      }
    }
    for (auto x : tot[n * m]) std::cout << x << " ";

    // std::cout << "\n";
    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < m; ++j) {
    //     auto [p, q] = tot[K(i, j)];
    //     std::ostringstream s;
    //     s << p << "/" << q;
    //     std::cout << std::left << std::setw(5) << s.str() << " ";
    //   }
    //   std::cout << "\n";
    // }

    std::cout << std::endl;
  }
  return 0;
}