#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mcd(ll a, ll b){
    if (b == 0){ 
        return a;
    }
    return mcd(b, a % b);
}
tuple<ll, ll, ll> alg_eu(ll a, ll b){
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, x1, y1] = alg_eu(b, a % b);
    return {g, y1, x1 - (a / b) * y1};
}
ll inverso(ll a, ll m){
    auto [g, x, y] = alg_eu(a, m);
    x = (x % m + m) % m;
    return x;
}
ll res(ll a1, ll m1, ll a2, ll m2){
    ll g = mcd(m1, m2);
    if ((a1 - a2) % g != 0){
        return -1;
    }
    ll p = m1 / g;
    ll q = m2 / g;
    ll dif = (a2 - a1) / g;
    dif = dif % q;
    if (dif < 0) {
        dif = dif + q;
    }
    ll inv = inverso(p % q, q);
    ll k = (dif * inv) % q;
    ll t = a1 + m1 * k;
    ll lcm = m1 / g * m2;
    t = t % lcm;
    if (t < 0) {
        t = t + lcm;
    }
    return t;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int casos;
    cin >> casos;
    while (casos > 0){
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector<pair<int,int>> arr(k);
        for (int i = 0; i < k; i++){
            cin >> arr[i].first >> arr[i].second;
        }       
        int x0 = arr[0].first;
        int y0 = arr[0].second;
        int gn = mcd(q, n);
        int gm = mcd(p, m);
        int np = n / gn;
        int mp = m / gm;
        ll invq = 0;
        ll invp = 0;
        if (np > 1){
            invq = inverso(q / gn, np);
        }
        if (mp > 1){
            invp = inverso(p / gm, mp);
        }
        ll mejor_t = LLONG_MAX;
        int mejor = -1;
        for (int i = 0; i < k; i++){
            int dx = (arr[i].first - x0) % n;
            if (dx < 0) {
                dx = dx + n;
            }
            int dy = (arr[i].second - y0) % m;
            if (dy < 0) {
                dy = dy + m;
            }
            
            if ((dx % gn) != 0){
                continue;
            }
            if ((dy % gm) != 0){
                continue;
            }
            ll t0 = 0;
            if (np > 1){
                t0 = ((dx / gn) * invq) % np;
            }
            ll t1 = 0;
            if (mp > 1){
                t1 = ((dy / gm) * invp) % mp;
            }
            ll t = res(t0, np, t1, mp);
            if (t == -1){
                continue;
            }
            if (t == 0){
                t = (ll)np / mcd(np, mp) * mp;
            }
            if (t < mejor_t){
                mejor_t = t;
                mejor = i;
            }
        }   
        cout << mejor << endl;
        casos = casos - 1;
    }
}