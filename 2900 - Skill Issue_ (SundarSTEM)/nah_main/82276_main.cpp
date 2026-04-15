/*
/$$$$$$$  /$$$$$$  /$$   /$$  /$$$$$$$  /$$$$$$$
|_  $$_/ /$$__  $$| $$  | $$ /$$__  $$ /$$__  $$
  | $$  | $$  \__/| $$  | $$| $$  \ $$| $$  \ $$
  | $$  |  $$$$$$ | $$$$$$$$| $$$$$$$$| $$  | $$
  | $$   \____  $$| $$__  $$| $$__  $$| $$  | $$
  | $$   /$$  \ $$| $$  | $$| $$  | $$| $$/$$ $$
 /$$$$$$|  $$$$$$/| $$  | $$| $$  | $$|  $$$$$$/
|______/ \______/ |__/  |__/|__/  |__/ \____ $$$
                                            \__/*/
 
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define CODE_BY_ISHAQ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define print(v) for (auto &x : v) cout << x << ' '; cout << '\n';
#define endl '\n'
#define int ll
 
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void add(int idx, ll val, vector <ll> &BIT, int n) {
  while (idx <= n) {
    BIT[idx] += val;
    idx += idx & -idx;
  }
}

ll sum(int idx, vector <ll> &BIT) {
  ll ans = 0;
  while (idx > 0) {
    ans += BIT[idx];
    idx = idx & -idx;
  } return ans;
}

void ishaq() {
  int N, P, R, K;
  cin >> N >> P >> R >> K;
  vector <int> e(N);
  for (int i = 0; i < N; i++) {
    cin >> e[i];
  } int curr = 0;
  for (int i = 0; i < N; i++) {
    P -= e[i];
    curr++;
    if (P < 0) {
      cout << "nah i’d lose\n";
      return;
    } if (curr == K) {
      P += R;
      curr = 0;
    }
  } cout << "nah i’d win\n";
}
 
signed main() {
  CODE_BY_ISHAQ;
  //#ifndef ONLINE_JUDGE
  //freopen("workspace/input.txt", "r", stdin); 
  //#endif
  int T = 1;
  cin >> T;
  while (T--) ishaq();
  return 0;
}