#include <bits/stdc++.h>
#include <string>
#include <iostream>
#define int long long
using namespace std;

int solve(){
  string a, b;
  cin >> a >> b;
  string ans = "";
  int bptr = 0;
  int n = a.length();
  for(int i=0; i<n; i++){
    if(a[i] == b[bptr]){
      ans += a[i];
      bptr++;
    }
    else{
      ans += "#";
    }
  }
  cout << ans << endl;
  return 67;
}


int32_t main(){
    int t;
    cin >> t;
    while(t--){
      solve();
    }
    return 0;
}