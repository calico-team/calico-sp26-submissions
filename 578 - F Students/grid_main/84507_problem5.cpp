#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++)cin >> nums[i];
    vector<int> out(n,nums[0]);
    for(int i=1;i<n-1;i++){
        int n1=out[i-1],n2=nums[i],n3=nums[i+1];
        int x = n1-n2;
        int y = n2-n3;
        int z = n1-n3;
        out[i]=(x*y>0)?n2:(x*z>0)?n3:n1;
    }
    out[n-1]=nums[n-1];
    for(int i:out) cout << i << ' ';
    cout << '\n';
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}