#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vt vector 
#define pb push_back
#define pob pop_back
#define endl '\n'
#define fi first
#define se second
 

signed main() {
      int t;
      cin >> t;
      while(t--){
          int l , w , e , r;
          cin >> l >> w >> e >> r;
          int p = 2*(l+w);
          cout << e/(p*r) << endl;
      }
      return 0;
}
