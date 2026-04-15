#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<ll> v;
        for(int i=0;i<n;i++){
            for(ll d=-1;d<=1;d++){
                ll x=a[i]+d;
                if(x>=1&&x<=2000000000)v.push_back(x);
            }
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        ll best=1e18;
        vector<ll> ans(n);
        int m=v.size();
        vector<ll> cur(n);
        function<void(int)> dfs=[&](int p){
            if(p==n){
                ll sum=0;
                for(int i=1;i<n;i++)sum+=abs(a[i]-a[i-1]);
                for(int i=0;i<n;i++){
                    if(i)sum+=abs(cur[i]-cur[i-1]);
                    sum+=abs(cur[i]-a[i]);
                }
                if(sum<best){
                    best=sum;
                    ans=cur;
                }
                return;
            }
            for(int i=0;i<m;i++){
                cur[p]=v[i];
                dfs(p+1);
            }
        };
        dfs(0);
        for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];
    }
    return 0;
}