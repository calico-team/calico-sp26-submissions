/*

*/

#include <bits/stdc++.h>

namespace kactl {}

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
  std::cin >> tn; std::cerr << "\e[1;31m\e[5m[!]\e[25m MULTITEST MODE \e[5m[!]\e[25m\e[0m" << std::endl;
  while (tn--) {
    ll n, p, r, k; // n p r k
    std::cin >> n >> p >> r >> k;
    vi e(n);
    for (auto &x : e) std::cin >> x;
    
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      p -= e[i];
      if (p < 0) ok = false;
      if (i % k == k-1) p += r;
    }
    std::cout << (ok ? "nah i'd win" : "nah i'd lose");
    

    std::cout << std::endl;
  }
  return 0;
}