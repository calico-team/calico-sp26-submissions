#include <iostream>
#include <vector>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    bool flag = false;
    int n, p, r, k;
    cin >> n >> p >> r >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int t = 0;
    for (const auto &x : a) {
      p -= x;
      if (p < 0) {
        flag = true;
        break;
      }
      t++;
      if (t >= k) {
        p += r;
        t = 0;
      }
    }
    if (flag == true) {
      cout << "nah i'd lose" << endl;
    } else {
      cout << "nah i'd win" << endl;
    }
  }
}