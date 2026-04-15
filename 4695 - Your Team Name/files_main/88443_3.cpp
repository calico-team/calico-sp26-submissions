#include <bits/stdc++.h>
using namespace std;

int t;
string a, b;

int main() {
  cin >> t;
  for (int ii = 0; ii < t; ii++) {
    cin >> a >> b;
    int x = a.size();
    int y = b.size();
    int u = 0, v = 0;
    string c;
    while (u < x && v < y) {
      if (a[u] == b[v]) {
        c.push_back(a[u]);
        u++;
        v++;
      } else {
        u++;
        c.push_back('#');
      }
    }
    cout << c << '\n';
  }
}
