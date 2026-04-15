#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

using ll=long long;

ll inv(ll a, ll m)
{
    if(gcd(a, m) !=1){
        return -1;
    }
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

pair<ll,ll> solve(ll x, ll y, ll eq, ll modu){
ll gc = gcd(y, modu);
ll per = modu/gc;
ll fin = ((eq-x)% modu + modu) % modu;
if(fin % gc !=0){
    return(make_pair(-1, -1));
}
ll yy = (y/gc)%per;
ll finala = (fin/gc)%per;
ll i = inv(yy, per);

if(i==-1){
    return make_pair(-1, -1);
}
ll T = (i * finala)% per;
return (make_pair(T, per));
}


ll crt (ll f, ll g, ll h, ll l){ 
if(f==-1 || h==-1){
    return -1;
}
ll gg = gcd(g, l);
ll fin = (((h-f) % l) + l) % l;
if(fin % gg !=0){
    return -1;
}
ll gc = g/gg;
ll l2 = l/gg;
ll finala = fin/gg;
ll k = (inv(gc, l2) * finala) % l2;
ll T = f+g*k;
return (T % lcm(g, l) + lcm(g, l)) % lcm(g, l);

for (ll T = f; T<g*l/gcd(g, l); T+=g){
    if(T % l ==h){
        return T;
    }
}
return -1;
}
int main(){
    ll x;
    cin >> x;
    for (ll i=0; i<x; i++){
        ll min=1e16;
        ll minindex=1e16;
        ll k;
        ll m, n, p,q;
        cin >> k >> n >> m >> p >> q;
        vector <pair<ll, ll>> v;
        ll xx, yy;
        for (ll ii=0; ii<k; ii++){
            cin >> xx >> yy;
            v.push_back(make_pair(xx, yy));
            ll TmodN, TmodM;
            ll a = v[0].first;
            ll b=v[0].second;
            pair <ll, ll> pq = solve(a, q, v[ii].first, n);
            pair <ll, ll> qp = solve(b, p, v[ii].second, m);
            ll crtt = crt(pq.first, pq.second, qp.first, qp.second);
            if(crtt==0){
                crtt = m*n/gcd(m,n);
            }
            if(crtt <min && crtt>0){
                min=crtt;
                minindex=ii;
            }
        }
        cout << minindex << endl;

    }

}