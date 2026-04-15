#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      int tot = i * 3;
      for (int j = 0; j < m; j++) {
        cout << (tot + j) % 5 << " ";
      }
      cout << "\n";
    }
  }
}
