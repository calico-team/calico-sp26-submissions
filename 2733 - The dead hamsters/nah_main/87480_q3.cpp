#include <bits/stdc++.h>
#include <string>
#include <iostream>
#define int long long
using namespace std;

string solve(){
  int n, p, r, k;
  cin >> n >> p >> r >> k;
  int e[10000];
  for(int i=0; i<n; i++){
    int g;
    cin >> g;
    e[i] = g;
  }
  int enemies_defeated = 0;
  for(int i=0; i<n; i++){
    p -= e[i];
    if(p<0){
      return "nah i'd lose";
    }
    enemies_defeated++;
    if(enemies_defeated % k == 0){
      p += r;
    }
  }
  return "nah i'd win";
}


int32_t main(){
    int t;
    cin >> t;
    while(t--){
      cout << solve() << endl;
    }
    return 0;
}