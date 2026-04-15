#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<pair<int, int> > LR (N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  LR[0] = {A[0], A[0]};
  for (int i = 1; i < N; i++) {
    if (A[i] < LR[i - 1].first) {
      LR[i] = {A[i], LR[i - 1].first};
    }
    else if (A[i] > LR[i - 1].second) {
      LR[i] = {LR[i - 1].second, A[i]};
    }
    else {
      LR[i] = {A[i], A[i]};
    }
  }

  vector<int> B(N);
  B[N - 1] = LR[N - 1].first;
  for (int i = N - 2; i >= 0; i--) {
    B[i] = min(max(B[i + 1], LR[i].first), LR[i].second);
  }
  for (int i = 0; i < N; i++) {
    cout << B[i] << ' ';
  }
  cout << '\n';
}

int main() {
  fastio;
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}