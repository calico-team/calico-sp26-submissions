#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, w, e, r;
    cin >> l >> w >> e >> r;
    int perimeter = 2 * (l + w);
    cout << e / (perimeter * r) << endl;
  }
}