#include <bits/stdc++.h>
#define int long long
#define arr3 array <int , 3>
#define pii pair <int , int>
#define fi first
#define se second
#define BIT(x , k) ((x >> k)&1)
#define MASK(x) (1 << x)

using namespace std;

const int maxn = 5e5 + 7;
const int INF = 1e18;

int n , a[maxn] , L[maxn] , R[maxn];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    //for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    L[1] = R[1] = a[1];
    for(int i = 2; i <= n; i++)
    {
        if(a[i] < L[i-1])
        {
            L[i] = a[i];
            R[i] = L[i-1];
        }
        else if(a[i] > R[i-1])
        {
            L[i] = R[i-1];
            R[i] = a[i];
        }
        else L[i] = R[i] = a[i];
        //cout << L[i] << ' ' << R[i] << '\n';
    }
    int cur = a[n];
    for(int i = n; i >= 1; i--)
    {
        cur = max(L[i], min(R[i], cur));
        a[i] = cur;
    }
    for(int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
    return 0;
}
