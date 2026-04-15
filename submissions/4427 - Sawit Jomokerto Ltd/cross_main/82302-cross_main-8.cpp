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
    ll n,m; cin >> n >> m;
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m; j++) {
            cout << (j+2*i) % 5 << " ";
        }
        cout << endl;
    }
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