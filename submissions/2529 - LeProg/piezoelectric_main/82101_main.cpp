#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t; cin >> t;
    for(ll ii = 0; ii<t; ii++){
        ll l,w,e,r; cin >> l >> w >> e >> r;
        ll p = 2*(l+w);
        cout << e/(p*r) << "\n";
    }
}