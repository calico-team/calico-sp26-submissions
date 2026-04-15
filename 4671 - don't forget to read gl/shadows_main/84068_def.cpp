#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n; 
  cin >> n;
  vector<string> a(n), b(n);
  for(int i=0; i<n; ++i) cin >> a[i];
  for(int i=0; i<n; ++i) cin >> b[i];
  int maxvol = 0, minvol = 0;
  for(int i=0; i<n; ++i){
    int r1 = 0, r2 =0;
    for(int j=0; j<n; ++j){
      if(a[i][j] == '#') r1++;
      if(b[i][j] == '#') r2++;
    }
    // i'm genuinely stupid
    // dump processing
    maxvol += r1 * r2;
    minvol += max(r1, r2);
  }
  cout << maxvol << ' ' << minvol << '\n';
}
  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t-->0)  solve();
} 