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
    int l,w,e,r;
    cin >> l >> w >> e >> r;
    cout << e/((2*(l+w))*r) << endl;
  }
}