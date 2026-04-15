#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,2> pii;
typedef array<ll,4> p4i;
ll MOD = 998244353;

ll fastexp(ll a, ll b) {
    if (!b) return 1;
    ll tmp = fastexp(a,b/2);
    tmp = (tmp*tmp)%MOD;
    if (b%2) tmp = (tmp*a)%MOD;
    return tmp;
}
// idx 0 = top
// idx 1 = bottom (yum)
//sasakoi
void kaomari_forever() {
    ll k,n,m,p,q; cin >> k >> n >> m >> p >> q;
    vector<pii> at;
    for (ll i = 0; i < k;i++) {
        ll x,y; cin >> x >> y;
        at.push_back({x,y});
    }
    map<p4i,ll> idxv;
    pii curcord = at[0];
    ll idx = 1;
    while (1) {
        ll mtp = min((((n-1)-curcord[0])/q),(((m-1)-curcord[1])/p));
        p4i line = {curcord[0],curcord[1],curcord[0] + mtp * q,curcord[1] + mtp * p};
        curcord = {(curcord[0] + (mtp)*q) % (n),(curcord[1] + (mtp)*p) % (m)};
        if (curcord[0] != 0 && curcord[1] != 0) {
            curcord[0] = (curcord[0]+q) % (n);
            curcord[1] = (curcord[1]+p) % (m);
        }
        if (idxv.count(line)) {
            break;
        }
        //cout << mtp << endl;
        //cout << curcord[0] << " " << curcord[1] << endl;
        //cout << line[0] << " " << line[1] << " " << line[2] << " " << line[3] << endl;
        idxv[line] = idx;
        idx++;
        //cout << endl;
    }
    //cout << endl;
    vector<pii> ans;
    ans.push_back({ll(1e9),0});
    for (ll i = 1; i < k;i++) {
        ll mtp1 = min((at[i][0]/q),(at[i][1]/p));
        ll mtp2 = min((((n-1)-at[i][0])/q),(((m-1)-at[i][1])/p));
        p4i line = {at[i][0] - mtp1*q , at[i][1] - mtp1*p,at[i][0] + mtp2*q , at[i][1] + mtp2*p};
        //cout << line[0] << " " << line[1] << " " << line[2] << " " << line[3] << endl;
        if (idxv.count(line)) {
            ans.push_back({idxv[line],i});
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans[0][1] << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--) {
        kaomari_forever();
    }
}