#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,2> pii;
ll MOD = 998244353;

ll fastexp(ll a, ll b) {
    if (!b) return 1;
    ll tmp = fastexp(a,b/2);
    tmp = (tmp*tmp)%MOD;
    if (b%2) tmp = (tmp*a)%MOD;
    return tmp;
}

//sasakoi
void kaomari_forever() {
    ll n,p,r,k; cin >> n >> p >> r >> k;
    vector<ll> a;
    for (ll i = 0; i < n;i++) {
        ll x; cin >> x; a.push_back(x);
    }
    ll kirk = 0;
    for (ll i = 0; i < n;i++) {
        if (p >= a[i]) {
            p -= a[i];
            kirk++;
        } else {
            cout << "nah i'd lose" << endl;
            return;
        }
        if (kirk == k) {
            kirk = 0;
            p += r;
        }
    }
    cout << "nah i'd win" << endl;
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