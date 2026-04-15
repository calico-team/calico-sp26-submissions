#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,2> pii;
typedef array<ll,4> p4i;

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
    vector<pair<p4i,ll>> v;
    vector<p4i> a,nw;
    for (ll i = 1; i < k;i++) {
        ll mtp1 = min((at[i][0]/q),(at[i][1]/p));
        ll mtp2 = min((((n-1)-at[i][0])/q),(((m-1)-at[i][1])/p));
        p4i line = {at[i][0] - mtp1*q , at[i][1] - mtp1*p,at[i][0] + mtp2*q , at[i][1] + mtp2*p};
        v.push_back({line,i});
        a.push_back(line);
    }
    sort(v.begin(),v.end());
    for (ll i = 0; i < v.size();i++) {
        nw.push_back(a[v[i].second-1]);
    }
    vector<pii> ans;
    ans.push_back({ll(1e9),0});
    pii curcord = at[0];
    for (ll j = 0; j <= n+m+1;j++) {
        ll mtp = min((((n-1)-curcord[0])/q),(((m-1)-curcord[1])/p));
        p4i line = {curcord[0],curcord[1],curcord[0] + mtp * q,curcord[1] + mtp * p};
        curcord = {(curcord[0] + (mtp)*q) % (n),(curcord[1] + (mtp)*p) % (m)};
        if ((curcord[0] != 0 && curcord[1] != 0) || mtp == 0) {
            curcord[0] = (curcord[0]+q) % (n);
            curcord[1] = (curcord[1]+p) % (m);
        }
        auto it = lower_bound(nw.begin(),nw.end(),line);
        if (it == nw.end()) continue;
        ll idx = it - nw.begin();
        if (nw[idx] == line) {
            if (v[idx].second == 0) continue;
            ans.push_back({j,v[idx].second});
        }
        //cerr << mtp << endl;
        //cerr << curcord[0] << " " << curcord[1] << endl;
        //cerr << line[0] << " " << line[1] << " " << line[2] << " " << line[3] << endl;
        //cerr << endl;
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