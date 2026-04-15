#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

using ll=long long;
pair<ll,ll> solve(ll x, ll y, ll eq, ll modu){
ll per = modu / gcd(y, modu);
for (ll T = 0; T <per; T++){
    if(((x+y*T) % modu) == ((eq) % modu)){
        return (make_pair(T, per));
    } 
}
return make_pair(-1, -1);
}

ll crt (ll f, ll g, ll h, ll l){
    
if(f==-1 || h==-1){
    return -1;
}
for (ll T = f; T<g*l/gcd(g, l); T+=g){
    if(T % l ==h){
        return T;
    }
}
return -1;
}
int main(){
    int x;
    cin >> x;
    for (int i=0; i<x; i++){
        ll min=1e16;
        ll minindex=1e16;
        int k;
        ll m, n, p,q;
        cin >> k >> n >> m >> p >> q;
        vector <pair<ll, ll>> v;
        ll xx, yy;
        for (int ii=0; ii<k; ii++){
            cin >> xx >> yy;
            v.push_back(make_pair(xx, yy));
            int TmodN, TmodM;
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