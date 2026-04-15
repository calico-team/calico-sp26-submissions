#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=1e5+10;
const int mod=998244353;
const int P=1e9+7;

void solve(){  
    string s,t;cin>>s>>t;
    int n=s.size(),m=t.size();
    string ans="";
    int px1=0,px2=0;
    while(px1<n&&px2<n){
        if(s[px1]==t[px2]) ans.push_back(s[px1]),px2++;
        else ans.push_back('#');
        px1++;
    }
    while(ans.size()<n) ans.push_back('#');
    cout<<ans<<endl;
}   

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    cin>>tc;
    while(tc--) solve();
}