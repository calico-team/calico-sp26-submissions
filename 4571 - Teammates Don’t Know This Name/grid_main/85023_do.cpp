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
          int n;
          cin >> n;
          int a , b , c;
          cin >> a >> b >> c;
          int ans = 1e9+1;
          int y = abs(a-b) + abs(b-c);
          int x = abs(a-b) + abs(a-c);
          int z = abs(c-b) + abs(c-a);
          ans = min(ans , x);
          ans = min(ans , y);
          ans = min(ans , z);
          if(ans == x)
         cout << a << " " << a << " " << a << endl;
         else if(ans == y)
         cout << b << " " << b << " " << b << endl;
         else
         cout << c << " " << c << " " << c << endl;
      }
      return 0;
}
