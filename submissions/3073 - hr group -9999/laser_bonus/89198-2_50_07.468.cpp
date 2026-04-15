#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t,k,n,m,p,q;
const int MAXK = 1e5+10;
ll x[MAXK], y[MAXK];

// https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/euclid.h
ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll inv(ll a, ll m){
    ll x,y;
    ll g = euclid(a,m,x,y);
    assert(g == 1);
    return (x%m+m)%m;
}

// https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/CRT.h
ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	if((a - b) % g) return -1;
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> k >> n >> m >> p >> q;
        swap(p,q);

        for(int i=1; i<=k; ++i) cin >> x[i] >> y[i];

        ll g1 = gcd(p,n);
        ll g2 = gcd(q,m);

        p /= g1;
        q /= g2;

        ll nbruh = n/g1;
        ll mbruh = m/g2;

        p = inv(p,nbruh);
        q = inv(q,mbruh);

        ll mn = lcm(nbruh,mbruh), ans = 1;
        for(int i=2; i<=k; ++i){
            ll X = (x[i] - x[1] + n) % n;
            ll Y = (y[i] - y[1] + m) % m;

            if(X % g1) continue;
            if(Y % g2) continue;

            X /= g1;
            Y /= g2;

            ll res = crt(X*p%nbruh,nbruh,Y*q%mbruh,mbruh);

            if(res == -1) continue;

            if(res < mn){
                mn = res;
                ans = i;
            }
        }

        cout << ans-1 << "\n";
    }
}
