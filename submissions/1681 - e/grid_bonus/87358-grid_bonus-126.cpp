#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long ll;

void solve()
{
    int n; cin>>n;
    vector<ll>v(n);
    vector<vector<ll>>dp(n, vector<ll>(2, INF));
    vector<vector<ll>>p(n, vector<ll>(2));
    for(int i =0;i<n;i++)cin>>v[i];
    dp[0][0] = 0;
    dp[0][1] = INF;
    for(int i =1;i<n;i++){
        if(dp[i-1][0] != INF){
            ll val = dp[i-1][0] + abs(v[i-1] - v[i]);
            if(val < dp[i][0]){
                dp[i][0] = val;
                p[i][0] = 0;
            }
            if(val < dp[i][1]){
                dp[i][1] = val1;
                p[i][1] = 0;
            }
        }
        if(i > 1 && dp[i-1][1] != INF){
            ll val = dp[i-1][1] + abs(v[i-2] - v[i]);
            if(val < dp[i][0]){
                dp[i][0] = val;
                p[i][0] = 1;
            }
            ll val1 = dp[i-1][1] + abs(v[i-2] - v[i-1]) + abs(v[i] - v[i-1]);
            if(val1 < dp[i][1]){
                dp[i][1] = val1;
                p[i][1] = 1;
            }
        }
    }
    vector<ll>a(n);
    int pos = 0;
    if(dp[n-1][1] < dp[n-1][0])pos = 1;
    for(int i =n-1;i>=0;i--){
        if(!pos)a[i] = v[i];
        else a[i] = v[i-1];
        pos = p[i][pos];
    }
    for(auto u : a) cout << u << " ";
    cout << "\n";
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