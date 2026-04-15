#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T, typename J>
using pi = pair<T,J>;
using vi = vector<int>;
using viLL = vector<ll>;
using vistr = vector<string>;
using vichar = vector<char>;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define repi(i, a, b) for(ll i = a; i <= b; ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define endl '\n' // no flush
#define space " "
#define slsp ios::sync_with_stdio(0); cin.tie(0);
/*************************/

int main(){
  slsp;
  int t;
  cin >> t;
  while(t--){
    int n,p,r,k;
    cin >> n >> p >> r >> k;
    // use r when k enemies are defeated
    vi a(n);
    trav(e,a){
      cin >> e;
    }
    int defeats = 0;
    bool win = true;
    rep(i,0,n){
      p -= a[i];
      defeats++;
      if (p<0){
        win = false;
        break;
      }
      if (defeats == k){
        p += r;
        defeats = 0;
      }
    }
    cout << (win?"nah i'd win":"nah i'd lose") << endl;
  }
}