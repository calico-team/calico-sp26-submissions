#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define int ll
#define all(x) x.begin(), x.end()

void solve(){
    
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    
    int p = (2*(a+b))*d;

    cout<<c/p<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin>>tc;
    while(tc--){
        solve();
    }
}