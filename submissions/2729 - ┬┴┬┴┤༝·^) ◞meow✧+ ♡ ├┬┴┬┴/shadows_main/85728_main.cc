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
    ll n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (auto &x : a) std::cin >> x;
    std::vector<std::string> b(n);
    for (auto &x : b) std::cin >> x;
    
    std::vector<std::bitset<1000>> A(n), B(n);
    std::vector<std::bitset<1000>> AT(n), BT(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        A[i][j] = a[i][j] == '#';
        B[i][j] = b[i][j] == '#';
        AT[j][i] = a[i][j] == '#';
        BT[j][i] = b[i][j] == '#';
      }
    }
    vi Ac(n), Bc(n);
    for (int i = 0; i < n; ++i) {
      Ac[i] = A[i].count();
      Bc[i] = B[i].count();
    }

    int min = 0;
    for (int i = 0; i < n; ++i) {
      min += std::max(Ac[i], Bc[i]);
    }
    int max =0 ;
    // i guess it is huh :thonk:
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (A[i][j]) max += Bc[i];
      }
    }
    std::cout << max << " " << min;

    std::cout << std::endl;
  }
  return 0;
}