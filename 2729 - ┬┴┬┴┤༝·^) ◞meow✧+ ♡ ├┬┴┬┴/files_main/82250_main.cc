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
    std::string s;
    std::cin >> s;
    std::string t;
    std::cin >> t;
    
    int j = 0;
    for (auto &c : s) {
      if (c == t[j] && j < t.size()) ++j;
      else c = '#';
    }
    std::cout << s;

    std::cout << std::endl;
  }
  return 0;
}