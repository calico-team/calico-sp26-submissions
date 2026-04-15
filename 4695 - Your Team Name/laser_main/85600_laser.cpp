#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll findMinX(ll coeff[], ll num[], ll rem[], int k) {
  ll x = 1;
  ll max_steps = num[0] * num[1];

  while (x <= max_steps) {
    int j;
    for (j = 0; j < k; j++) {
      if ((x * coeff[j]) % num[j] != rem[j]) {
        break;
      }
    }
    if (j == k) {
      return x;
    }
    x++;
  }
  return -1;
}
int solve() {
  int K;
  ll N, M, P, Q;
  cin >> K >> N >> M >> P >> Q;
  vector<ll> X(K), Y(K);
  for (int i = 0; i < K; i++)
    cin >> X[i] >> Y[i];

  ll min_t = -1;
  int best_asteroid = -1;

  for (int i = 0; i < K; i++) {
    ll dx = (X[i] - X[0] % N + N) % N;
    ll dy = (Y[i] - Y[0] % M + M) % M;

    ll coeff[] = {Q, P};
    ll num[] = {N, M};
    ll rem[] = {dx, dy};

    ll t = findMinX(coeff, num, rem, 2);

    if (t != -1 && (best_asteroid == -1 || t < min_t)) {
      min_t = t;
      best_asteroid = i;
    }
  }

  cout << best_asteroid << "\n";
  return 1;
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
