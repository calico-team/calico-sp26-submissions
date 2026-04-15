#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<ll, ll> pll;

#define sp << " " <<
#define debug(x) cout << x << endl
#define sz(x) (ll)(x.size())

const ll MOD=1e9+7;
const ll MOD1=998244353;
const ll INF=1e9;
const ll BIG=1e18;
const ll MX=2e5+5;
const double PI=acos(-1);

ll x8[8]={-1, -1, -1, 0, 0, 1, 1, 1};
ll y8[8]={-1, 0, 1, -1, 1, -1, 0, 1};

/*
position after n steps will be 
(x+tq)%n, (y+tp)%m
cuz p and q are positive

we check if it hits each asteroid
(x+tq)%n=x[i], (y+tp)%m=y[i]
-> tq mod n=(x[i]-x) mod n, tp mod m=(y[i]-y) mod m (precompute RHS)
-> find if such t exists, then find minimum

how to find tq=k mod n?
impos if gcd(q, n) is not a factor of k -> otherwise divide both sides by that
other impos condition?

becomes t*q/gq=k/gq mod n/gq
because coprime, take mod inverse of q/gq mod n/gq
*/

ll inv(ll a, ll b) {
    return (1LL<a?b-inv(b%a, a)*b/a:1LL);
}

void solve() {
    // i hate this question
    ll k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    ll gq=__gcd(q, n), gp=__gcd(p, m);
    vll x(k), y(k);
    // 0-indexing is goated
    for (ll i=0; i<k; i++) cin >> x[i] >> y[i];
    ll sx=x[0], sy=y[0];
    ll mnt=BIG, out=-1;
    for (ll i=0; i<k; i++) {
        ll distx=(x[i]-sx+n)%n, disty=(y[i]-sy+m)%m;
        // find tq=distx and tp=disty
        if (distx%gq) continue;
        if (disty%gp) continue;
        ll tdx=distx/gq, tqx=q/gq, tnx=n/gq;
        ll tdy=disty/gp, tpy=p/gp, tny=m/gp;
        ll tx=(tdx*inv(tqx, tnx))%tnx, ty=(tdy*inv(tpy, tny))%tny;
        // t=tx mod tnx and ty mod tny
        ll ga=__gcd(tnx, tny);
        if ((ty-tx)%ga) continue;
        ll nnx=tnx/ga, nny=tny/ga;
        ll tem=((ty-tx)/ga)%nny;
        if (tem<0) tem+=nny;
        tem*=inv(nnx, nny); tem%=nny;
        ll curt=tx+tnx*tem;
        if (curt==0) curt=lcm(tnx, tny);
        if (curt<mnt) {
            mnt=curt;
            out=i;
        }
    }
    cout << out << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll tc=1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}