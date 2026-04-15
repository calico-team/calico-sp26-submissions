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
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
  int K, N, M, P, Q;
  cin >> K >> N >> M >> P >> Q;
  vector <pair <int, int>> e;
  map <pair <int, int>, int> freq;
  for (int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;
    freq[{x, y}]++;
    e.pb({x, y});
  } int X = e[0].F, Y = e[0].S;
  int a = -1, b = -1;
  int m = 0;
  while (true) {
    X += Q;
    Y += P;
    if (X >= N) {
      X = (X-N)%N;
    } if (Y >= M) {
      Y = (Y-M)%M;
    } if (freq[{X, Y}]) {
      a = X;
      b = Y;
      break;
    }
  } for (int i = 0; i < K; i++) {
    if (e[i].F == a and e[i].S == b) {
      cout << i << endl;
      return;
    }
  }
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