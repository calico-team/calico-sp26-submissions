#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long ll;

void solve()
{
    int n; cin>>n;
    vector<int>row(n), col(n);
    for(int i =0;i<n;i++){
        string s; cin>>s;
        for(auto u : s){
            if(u == '#') row[i]++;
        }
    }
    for(int i =0;i<n;i++){
        string s; cin>>s;
        for(auto u : s){
            if(u == '#')col[i]++;
        }
    }
    ll mn = 0, mx = 0;
    for(int i =0;i<n;i++){
        mn += max(row[i], col[i]);mx += (row[i] * col[i]);
    }
    cout << mx << " "<< mn << "\n";
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