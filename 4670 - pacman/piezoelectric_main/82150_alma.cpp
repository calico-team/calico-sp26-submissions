#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
const int B = 1e3 + 5;

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int l, w, e, r;
    cin >> l >> w >> e >> r;
    int cur = e / r;
    cout << cur / ((l + w) * 2) << endl;
  }
}