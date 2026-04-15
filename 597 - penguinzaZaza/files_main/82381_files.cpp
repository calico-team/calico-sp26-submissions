#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;

    int in2 = 0;

    for (auto x : a) {
      if (in2 == b.size()) {
        cout << "#";
      } else if (x == b[in2]) {
        cout << x;
        in2++;
      } else {
        cout << "#";
      }
    }
    cout << endl;
  }
}
