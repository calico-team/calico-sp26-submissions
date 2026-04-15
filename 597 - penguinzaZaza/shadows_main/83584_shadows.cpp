#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> vs1(n), vs2(n);
    for (auto &s : vs1)
      cin >> s;
    for (auto &s : vs2)
      cin >> s;

    int mini = 0, maxi = 0;
    for (int i = 0; i < n; i++) {
      int ct1 = 0, ct2 = 0;
      for (auto x : vs1[i])
        ct1 += x == '#';
      for (auto x : vs2[i])
        ct2 += x == '#';

      maxi += ct1 * ct2;
      mini += max(ct1, ct2);
    }

    cout << maxi << " " << mini << "\n";
  }
}
