#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=1e5+10;
const int mod=998244353;
const int P=1e9+7;

void solve(){
    int n,p,r,k;cin>>n>>p>>r>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        bool f=0;
        if((i-1)%k==0&&i-1>0) f=1;
        if(p>=a[i]) p-=a[i];
        else if(f) {
            if(p+r<a[i]){
                cout<<"nah i'd lose"<<endl;return ;
            } 
            p=p+r-a[i];
        }else{
            cout<<"nah i'd lose"<<endl;return ;                          
        }
    }
    cout<<"nah i'd win"<<endl;
}   

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    cin>>tc;
    while(tc--) solve();
}