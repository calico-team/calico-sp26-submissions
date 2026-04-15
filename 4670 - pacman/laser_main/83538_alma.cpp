#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
const int B = 1e3 + 5;

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    set < array < int , 2 > > st;
    vector < array < int , 2 > > xy(k);
    for(int i = 0; i < k; i++){
      cin >> xy[i][0] >> xy[i][1];
      st.insert({xy[i][0], xy[i][1]});
    }
    int xs = xy[0][0], ys = xy[0][1];
    do {
      xs += q, ys += p;
      xs %= n, ys %= m;
    }while(st.count({xs, ys}) == 0);
    for(int i = 0; i < k; i++){
      if(xs == xy[i][0] && xy[i][1] == ys){
        cout << i << endl;
        break;
      }
    }
  }
}