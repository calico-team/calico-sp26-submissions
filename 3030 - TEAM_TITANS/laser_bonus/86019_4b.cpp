#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


ll mod_inv(ll a, ll m) {
    ll x, y;
    ll g = gcd(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

struct Congruence{ 
    ll r, m; 
};


Congruence solveLinear(ll A, ll B, ll M) {
    ll x, y;
    ll g = gcd(A, M, x, y);
    if (B%g!=0) return {-1, -1};
    
    ll m_br = M/g ; 
    ll a_br = A/g;
    ll b_br = B/g;
    
    ll inv = mod_inv(a_br, m_br);
   
    ll r = (ll)(((inv) * (b_br % m_br + m_br)) % m_br);
    return {r, m_br};
}


Congruence gcrt(Congruence c1, Congruence c2) {
    if (c1.m == -1 || c2.m == -1) return {-1, -1};
    
    ll x, y;
    ll g = gcd(c1.m, c2.m, x, y);
    ll diff = c2.r - c1.r;
    
    if (diff%g!= 0) return {-1, -1};

    ll m1_g = c1.m/g;
    ll m2_g = c2.m/g;
    ll diff_g = diff/g;

    ll inv = mod_inv(m1_g%m2_g,m2_g);
    
   
    ll k = (ll)((((diff_g % m2_g + m2_g) % m2_g) * inv) % m2_g);

    ll r_new = c1.r + k * c1.m;
    ll m_new = c1.m * m2_g;

    return {r_new, m_new};
}

void solve() {
    int K;
    ll N, M, P, Q;
    cin>>K>>N>>M>>P>>Q ;
    

    vector<pair<ll,ll>>asteroids(K);
    for (int i=0; i<K;i++) {
        cin>>asteroids[i].first>>asteroids[i].second;
    }

    ll startX = asteroids[0].first;
    ll startY = asteroids[0].second;

    ll min_t = -1;
    int best_idx = -1;

    for (int i = 0; i < K; ++i) {
        ll dx = (asteroids[i].first - startX) % N;
        if (dx<0) dx += N;
        
        ll dy = (asteroids[i].second - startY) % M;
        if (dy < 0) dy+=M;
        Congruence cx = solveLinear(Q,dx,N);
        Congruence cy = solveLinear(P,dy,M);
        Congruence c = gcrt(cx, cy);
        if (c.m == -1) continue;
        ll t = c.r;
        if (t == 0) t = c.m;
        if (min_t==-1||t < min_t) {
            min_t = t;
            best_idx = i;
        }
    }

    cout<<best_idx<<"\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T ; 
    while(T--) {
        solve();
    }
    
}