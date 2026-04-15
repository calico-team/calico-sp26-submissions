#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef _debug
#include </home/tonyz/templates/debug.cpp>
#else
#define debug(...) 42
#endif

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define vt vector
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ub upper_bound
#define lb lower_bound


const int inf = (int)2e9, mod = (int)1e9 + 7, mx = (int)2e5 + 10;
const ll infll = (ll)7e18;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll x1, y1;
  ll d = extended_euclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
ll inverse(ll a, ll m) {
  ll x, y;
  ll g = extended_euclid(a, m, x, y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
// ax = b (mod m)
vector<ll> congruence_equation(ll a, ll b, ll m) {
  vector<ll> ret;
  ll g = gcd(a, m), x;
  if (b % g != 0) return ret;
  a /= g, b /= g;
  x = inverse(a, m / g) * b;
  for (int k = 0; k < 1; ++k) { // exactly g solutions
    ret.push_back((x + m / g * k) % m);
  }
  // minimum solution = (m / g - (m - x) % (m / g)) % (m / g)
  return ret;
}
using T = __int128;
// ax + by = __gcd(a, b)
// returns __gcd(a, b)
T extended_euclid(T a, T b, T &x, T &y) {
  T xx = y = 0;
  T yy = x = 1;
  while (b) {
    T q = a / b;
    T t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
  }
  return a;
}
// finds x such that x % m1 = a1, x % m2 = a2. m1 and m2 may not be coprime
// here, x is unique modulo m = lcm(m1, m2). returns (x, m). on failure, m = -1.
pair<T, T> CRT(T a1, T m1, T a2, T m2) {
  T p, q;
  T g = extended_euclid(m1, m2, p, q);
  if (a1 % g != a2 % g) return make_pair(0, -1);
  T m = m1 / g * m2;
  p = (p % m + m) % m;
  q = (q % m + m) % m;
  return make_pair((p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) %  m, m);
}
void solve(){
    ll k, n, m, p, q; cin >> k >> n >> m >> p >> q;
    map<pii, int> key; pii st; 
    vector<ll> x(k), y(k); 
    for(int i = 0; i < k; i++){
        cin >> x[i] >> y[i]; 
        if(i == 0){
            st = {x[i], y[i]}; 
        }
    }
    ll ans = infll, id = -1;  
    for(int i = 0; i < k; i++){
        int mdx = (x[i] - st.first + n) % n;
        int mdy = (y[i] - st.second + m) % m; 
        //tq = mdx (mod N) 
        //t * q + N * k = mdx 
        //bezouts 
        if(mdx % (gcd(n, q)) != 0)continue;
        if(mdy % (gcd(m, p)) != 0)continue;
        vector<ll> xx = congruence_equation(q, mdx, n);
        vector<ll> yy = congruence_equation(p, mdy, m);
        assert(!xx.empty()); assert(!yy.empty());
        ll xxx = (xx[0] % (n/gcd(n, q))), yyy = (yy[0] % (m/gcd(m, p)));
        auto g = CRT(xxx, n/gcd(n,q), yyy, m / gcd(m, p));
        if(g.second == -1)continue;
        if(i == 0){
            g.first += g.second; 
        }
        if(g.first < ans){
            ans = g.first, id = i; 
        }
    }
    cout << id << '\n';
    

    //x + tq = xi (mod N) 
    //y + tp = yi (mod M)
    //tq = xi - x (mod N)
    //tp = yi - y (mod M)
    //
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}

