// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define eb emplace_back // faster than push_back xD

// pbds UwU
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define oset tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> // use pair for ms

// my io library :D
#define m1(x) template<class T, class... U> void x(T&& a, U&&... b)
#define m2(x) (ll[]){(x forward<U>(b),0)...}

m1(pr){cout << forward<T>(a);  m2(cout << " " <<); cout << "\n";}
m1(re){cin >> forward<T>(a); m2(cin >>);}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; re(t);
    for (ll i{}; i < t; i++){
        ll n, p, r, k; re(n, p, r, k);
        vector<ll> e(n);
        for (ll j{}; j < n; j++){
            re(e[j]);
        }
        ll pow = p;
        bool ok = true;

        for (ll j{}; j < n; j++) {
            pow -= e[j];
            if (pow < 0) {         
                ok = false;
                break;
            }
            if ((j+1) % k == 0) {
                pow += r;         
            }            
        }
        if (ok) pr("nah i'd win");
        else pr("nah i'd lose");
    }
}
