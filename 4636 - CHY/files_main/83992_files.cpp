#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string a, b, ans;
    cin >> a >> b;
    int index_b = 0;
    for (const auto &x : a) {
      if (x == b[index_b]) {
        ans += x;
        index_b++;
        if (index_b >= b.size()) {
          for (int i = ans.size(); i < b.size(); i++) {
            ans += "#";
          }
          break;
        }
      } else {
        ans += "#";
      }
    }
    cout << ans << endl;
  }
}