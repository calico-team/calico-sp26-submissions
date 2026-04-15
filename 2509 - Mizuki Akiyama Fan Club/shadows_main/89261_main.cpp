#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define endl "\n"

constexpr int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<string> grid1(n);
    for (int i = 0; i < n; i++) {
        cin >> grid1[i];
    }
    vector<string> grid2(n);
    for (int i = 0; i < n; i++) {
        cin >> grid2[i];
    }
    ll mx = 0;
    ll mn = 0;
    for (int i = 0; i < n; i++) {
        int c1 = 0;
        int c2 = 0;
        for (int j = 0; j < n; j++) {
            c1 += (grid1[i][j] == '#');
            c2 += (grid2[i][j] == '#');
        }
        mx += c1*c2;
        mn += max(c1, c2);
    }
    cout << mx << " " << mn << endl;
}

int main() {
    cin.tie(0);     
    ios_base::sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
 
    for (int tc = 0; tc < t; tc++) {
        solve();
    }
 
    return 0;
}