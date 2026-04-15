#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll findgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll gcd = findgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return gcd;
}

pair<ll, ll> solve_congruence(ll a, ll b, ll m) {
  ll x, y;
  ll g = findgcd(a, m, x, y);
  if (b % g != 0)
    return {-1, -1};

  ll mod = m / g;
  ll res = ((x % mod) * ((b / g) % mod)) % mod;
  return {(res + mod) % mod, mod};
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

    auto solX = solve_congruence(Q, dx, N);
    auto solY = solve_congruence(P, dy, M);

    if (solX.first == -1 || solY.first == -1)
      continue;

    ll a1 = solX.first, m1 = solX.second;
    ll a2 = solY.first, m2 = solY.second;

    ll x, y;
    ll g = findgcd(m1, m2, x, y);

    if ((a2 - a1) % g != 0)
      continue;

    ll cmod = (m1 / g) * m2;

    ll t = (a1 + (ll)((__int128)x * ((a2 - a1) / g) % (m2 / g) * m1)) % cmod;
    ll final_t = (t + cmod) % cmod;

    if (final_t == 0)
      final_t = cmod;

    if (best_asteroid == -1 || final_t < min_t) {
      min_t = final_t;
      best_asteroid = i;
    }
  }

  cout << best_asteroid << "\n";
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while (T--)
    solve();

  return 0;
}
