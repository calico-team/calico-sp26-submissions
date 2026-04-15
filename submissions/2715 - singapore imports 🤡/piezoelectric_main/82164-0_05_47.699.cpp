#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define l(a, b, i) for (ll i = a; i < b; i++)
#define rl(a, b, i) for (ll i = a; i >= b; i--)
#define vpair vector<pair<ll, ll>>
#define inf LLONG_MAX
#define ninf LLONG_MIN

void solve() {
    ll L, W, E, R; cin >> L >> W >> E >> R;
    ll gen = ((L + W) * 2)  * R;
    cout << E / gen << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while (T--) solve();
}