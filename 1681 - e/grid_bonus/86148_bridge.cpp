#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long ll;

void solve()
{
    int n; cin>>n;
    vector<ll>v(n), a(n), b(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
        a[i] = v[i];
    }
    sort(a.begin(), a.end());
    int mid = a[n / 2];
    for(int i =0;i<n;i++)b[i] = mid;
    ll d1 = 0, d2 = 0, d3 = 0;
    for(int i=1;i<n;i++)d1 += abs(v[i] - v[i-1]);
    for(int i = 1;i<n;i++)d2 += abs(b[i] - b[i-1]);
    for(int i =0;i<n;i++)d3 += abs(b[i] - v[i]);
    if(2 * d1 <= d1 + d2 + d3){
        for(auto u : v) cout << u << " ";
        cout << "\n";
    }
    else{
        for(auto u : b) cout << u << " ";
        cout << "\n";
    }
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