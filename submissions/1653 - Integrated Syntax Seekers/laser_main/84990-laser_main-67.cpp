// problem: https://calicojudge.com/team/problems/862/statement
// time complexity: O(n logn)
// i/o: stdio
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
template<typename T>
using v = vector<T>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

ll egcd(ll a, ll b, ll &x, ll &y){
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll modinv(ll a, ll m){
    ll x, y;
    egcd(a, m, x, y);
    x %= m;
    if(x < 0) x += m;
    return x;
}

pair<ll,ll> crt(ll a1, ll m1, ll a2, ll m2){
    ll x, y;
    ll g = egcd(m1, m2, x, y);

    if((a2 - a1) % g != 0) return {-1, -1};

    ll lcm = m1 / g * m2;

    ll mul = (a2 - a1) / g;
    x %= (m2 / g);
    if(x < 0) x += (m2 / g);

    ll t = (a1 + m1 * ((mul % (m2 / g)) * x % (m2 / g))) % lcm;
    if(t < 0) t += lcm;

    return {t, lcm};
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--)
    {
        // input
        int k, n, m, p, q; cin >> k >> n >> m >> p >> q;

        v<pair<int, int>> a(k);
        for(auto& i: a)
            cin >> i.first >> i.second;

        // algo
        ll x0 = a[0].first;
        ll y0 = a[0].second;

        ll best_t = LLONG_MAX;
        int x = -1;

        for(int i = 0; i < k; i++)
        {
            ll xi = a[i].first;
            ll yi = a[i].second;

            ll dx = (xi - x0) % n;
            if(dx < 0) dx += n;

            ll dy = (yi - y0) % m;
            if(dy < 0) dy += m;

            // solve tQ ≡ dx (mod n)
            ll g1 = std::gcd(q, n);
            if(dx % g1 != 0) continue;

            ll n1 = n / g1;
            ll q1 = q / g1;
            ll dx1 = dx / g1;

            ll invQ = modinv(q1 % n1, n1);
            ll tx = (dx1 * invQ) % n1;

            // solve tP ≡ dy (mod m)
            ll g2 = std::gcd(p, m);
            if(dy % g2 != 0) continue;

            ll m1 = m / g2;
            ll p1 = p / g2;
            ll dy1 = dy / g2;

            ll invP = modinv(p1 % m1, m1);
            ll ty = (dy1 * invP) % m1;

            auto [tval, lcm] = crt(tx, n1, ty, m1);
            if(tval == -1) continue;

            if(i == 0 && tval == 0)
                tval = lcm;

            if(tval == 0) continue;

            if(tval < best_t){
                best_t = tval;
                x = i;
            }
        }

        // output
        cout << x << '\n';
    }

    return 0;
} 