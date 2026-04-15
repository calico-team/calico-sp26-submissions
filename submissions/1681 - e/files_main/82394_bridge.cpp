#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long ll;

void solve()
{
    string a, b; cin>>a>>b;
    int j = 0;
    for(int i=0;i<a.size();i++){
        if(j < b.size() && a[i] == b[j])++j;
        else a[i] = '#';
    }
    cout << a << "\n";
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