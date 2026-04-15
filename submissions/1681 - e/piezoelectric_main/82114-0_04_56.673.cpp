#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long ll;

void solve()
{
    ll l, w, e, r; cin>>l>>w>>e>>r;
    ll x = 2 *(l + w) * r;
    ll y = e / x;
    cout << y << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}