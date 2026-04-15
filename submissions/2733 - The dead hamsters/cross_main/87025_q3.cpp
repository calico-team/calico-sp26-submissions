#include <bits/stdc++.h>
#include <string>
#include <iostream>
#define int long long
using namespace std;

int solve(){
  int m, n;
  cin >> m >> n;
  int a[1000][1000];
  int count = -1;
  for(int i=0; i<m; i++){
    if(i!=0){
      count = (a[i-1][0]+1)%5;
    }
    for(int j=0; j<n; j++){
      count++;
      a[i][j] = count%5;
    }
  }
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
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