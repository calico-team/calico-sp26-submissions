
#include <bits/stdc++.h>
#define int long long
#define arr3 array <int , 3>
#define pii pair <int , int>
#define fi first
#define se second
#define BIT(x , k) ((x >> k)&1)
#define MASK(x) (1 << x)

using namespace std;

const int maxn = 1e3 + 7;
const int INF = 1e18;

int n;
string s1[maxn] , s2[maxn];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s1[i];
    for(int i = 1; i <= n; i++) cin >> s2[i];

    if(n == 1)
    {
        if(s1[1][1] == '.') cout << 0 << ' ' << 0 << '\n';
        else cout << 1 << ' ' << 1 << '\n';
        return;
    }
    int mn = 0;
    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
        int cnt1 = 0 , cnt2 = 0;
        for(int j = 0; j < n; j++)
        {
            cnt1 += (s1[i][j] == '#');
            cnt2 += (s2[i][j] == '#');
        }
        mx += cnt1*cnt2;
        mn += max(cnt1 , cnt2);
    }
    cout << mx << " " << mn << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
    return 0;
}
