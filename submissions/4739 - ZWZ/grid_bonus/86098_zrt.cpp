#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=1e5+10;
const int mod=998244353;
const int P=1e9+7;

int a[4],b[4],ans=LLONG_MAX,n,op[4];

inline void dfs(int i){
    if(i==n+1){
        int sum=0;
        for(int j=2;j<=n;j++) sum+=abs(a[j]-a[j-1])+abs(b[j]-b[j-1])+abs(a[j]-b[j]);
        sum+=abs(b[1]-a[1]);
        if(ans>sum){
            for(int j=1;j<=n;j++) op[j]=b[j];
            ans=sum;
        }
        return ;
    }
    b[i]=a[i];
    dfs(i+1);
    if(i==1) return ;
    b[i]=b[i-1];
    dfs(i+1);
}

void solve(){cin>>n;   
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    for(int i=1;i<=n;i++) cout<<op[i]<<' ';
    cout<<endl;
}   

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    cin>>tc;
    while(tc--) solve();
}