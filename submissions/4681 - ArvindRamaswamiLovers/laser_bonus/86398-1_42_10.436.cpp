#include <bits/stdc++.h>
using namespace std;
using ll =long long;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}
ll extgcd(ll a, ll b,ll &x,ll &y){
    if (b ==0) {
        x =1;y =0;
        return a;
    }
    ll x1,y1;
    ll g =extgcd(b,a % b, x1, y1);
    x = y1;
    y =x1- (a /b)* y1;
    return g;
}

pair<ll,ll> solve_linear(ll a,ll b, ll m){
    ll x, y;
    ll g =extgcd(a, m, x, y);
    if (b %g !=0)return {-1,-1};
    
    ll mod = m /g;
    ll k0 = (x*(b /g)) % mod;
    if (k0<0) k0 += mod;
    return {k0, mod};
}

pair<ll,ll> crt(ll a, ll n,ll b,ll m) {
    ll x, y;
    ll g =extgcd(n, m, x, y);
    
    if ((b -a)% g !=0)return {-1, -1};
    ll lcm=n /g * m;
    ll t =((b -a) /g % (m/g) * x) % (m/g);
    ll res= (a + n *t)% lcm;
    
    if (res <0)res += lcm;
    return {res, lcm};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >>T;
    while (T--) {
        int K;
        ll N, M, P, Q;
        cin >> K>>N >> M >>P >> Q;

        vector<pair<ll,ll>>a(K);
        for (int i =0; i <K; i++) {
            cin >>a[i].first >> a[i].second;
        }

        ll x0 = a[0].first;
        ll y0 =a[0].second;

        ll best_k= LLONG_MAX;
        int best_idx = 0;

        for (int i = 0;i< K; i++) {
            ll dx =(a[i].first -x0 + N) % N;
            ll dy = (a[i].second - y0 +M) % M;
            auto sx = solve_linear(Q, dx, N);
            if (sx.first ==-1) continue;
            auto sy = solve_linear(P, dy, M);
            if(sy.first== -1) continue;
            auto res = crt(sx.first, sx.second, sy.first, sy.second);
            if (res.first ==-1) continue;
            ll k = res.first;
            if (k == 0){
                k = res.second;
            }

            if(k< best_k) {
                best_k =k;
                best_idx = i;
            }
        }

        cout <<best_idx << '\n';
    }
}