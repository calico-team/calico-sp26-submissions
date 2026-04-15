#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i == 0) {
        l[i] = a[i];
        r[i] = a[i];
      } else {
        l[i] = min(r[i - 1], a[i]);
        r[i] = max(l[i - 1], a[i]);
      }
    }
    b[n - 1] = l[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      b[i] = max(l[i], min(r[i], b[i + 1]));
    }
    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << endl;
  }
}