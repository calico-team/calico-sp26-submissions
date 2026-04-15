#include <bits/stdc++.h>
#include <string>
#include <iostream>
#define int long long
using namespace std;

int solve(){
  int l, w, e, r;
  cin >> l >> w >> e >> r;
  int ans = e/(2*(l+w)*r);
  cout << ans << endl;
  return 0;
}


int32_t main(){
    int t;
    cin >> t;
    while(t--){
      solve();
    }
    return 0;
}