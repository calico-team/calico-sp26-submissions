#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t; cin >> t;
    while (t--){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll peri = 2 * (a + b) * d;
        ll ans = (c + (peri - 1)) / peri;
        cout << ans << endl;
    }
}