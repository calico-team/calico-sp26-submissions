#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];
  vector<int> l(n), r(n);
  multiset<int> ms;
  ms.insert(a[0]);
  ms.insert(a[0]);
  l[0] = a[0];
  r[0] = a[0];
  for(int i=1; i<n; ++i){
    ms.insert(a[i]);
    ms.insert(a[i]);
    ms.erase(ms.begin());
    ms.erase(prev(ms.end()));
    l[i] = *ms.begin();
    r[i] = *ms.rbegin();
  }
  vector<int> b(n);
  b[n-1] = a[n-1];
  for(int i=n-2; i>=0; --i) b[i] = max(l[i], min(b[i+1], r[i]));
  for(int i=0; i<n; ++i) cout << b[i] << " \n"[i == n-1];
}
  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t-->0)  solve();
} 