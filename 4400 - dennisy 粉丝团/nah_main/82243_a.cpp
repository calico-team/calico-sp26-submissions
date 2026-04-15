#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void solve() {
  int N, P, R, K;
  cin >> N >> P >> R >> K;
  vector<int> E(N);
  for (int i = 0; i < N; i++) {
    cin >> E[i];
  }

  int defeated = 0;
  for (int i = 0; i < N; i++) {
    P -= E[i];

    if (P < 0) {
      cout << "nah i'd lose" << '\n';
      return;
    }

    defeated++;
    if (defeated == K) {
      defeated = 0;
      P += R;
    }
  }
  cout << "nah i'd win" << '\n';
}

int main() {
  fastio;
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
}