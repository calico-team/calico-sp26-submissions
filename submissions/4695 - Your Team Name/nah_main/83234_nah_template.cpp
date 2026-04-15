#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * Output whether Gojo will win the fight.
 *
 * N: Number of curses
 * P: Gojo's starting power
 * R: Amount of power Gojo can restore with Reverse Cursed Technique
 * K: The cooldown of Reverse Cursed Technique
 * E: List of power levels of curses
 */
string solve(ll N, ll P, ll R, ll K, vector<ll> E) {
  for (ll i = 0; i < N; i++) {
    P -= E[i];
    if (P < 0) {
      return "nah i'd lose";
    }
    if (((i + 1) % K) == 0) {
      P += R;
    }
  }
  return "nah i'd win";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T;
  cin >> T;
  for (ll i = 0; i < T; i++) {
    ll N, P, R, K;
    cin >> N >> P >> R >> K;
    vector<ll> E(N);
    for (ll j = 0; j < N; j++) {
      cin >> E[j];
    }
    cout << solve(N, P, R, K, E) << '\n';
  }
}
