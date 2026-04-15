#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string a, b; 
  cin >> a >> b;
  int n = a.size(), m  = b.size();
  vector<multiset<int>> pos(256);
  for(int i=0; i<n; ++i) pos[a[i]].insert(i);
  int last = -1;
  vector<bool> keep(n);
  for(int i=0; i<m; ++i) {
    auto it = pos[b[i]].upper_bound(last);
    keep[*it] = true;
    last = *it;
  }
  for(int i=0; i<n; ++i) if(!keep[i]) a[i] = '#';
  cout << a << '\n';
}
  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t-->0)  solve();
} 