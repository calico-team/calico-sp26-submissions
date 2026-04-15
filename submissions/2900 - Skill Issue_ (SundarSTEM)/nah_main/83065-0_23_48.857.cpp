#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, P, R, K;
    cin >> N >> P >> R >> K;
    vector <int> e(N);
    for (int i = 0; i < N; i++) {
      cin >> e[i];
    } int curr = 0;
    bool possible = true;
    for (int i = 0; i < N; i++) {
      P -= e[i];
      curr++;
      if (P < 0) {
        possible = false;
        break;
      } if (curr == K) {
        P += R;
        curr = 0;
      }
    } cout << (possible ? "nah i’d win\n" : "nah i'd lose\n");
  }
  return 0;
}