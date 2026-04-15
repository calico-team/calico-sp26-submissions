#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int T,n;
ll a[N],b[N];
priority_queue<ll> L;
priority_queue<ll,vector<ll>,greater<ll>> R;
ll ans;
void add(ll x){
    if(L.empty()||x<=L.top()){
        L.push(x);
        if(L.size()>R.size()+1){
            R.push(L.top());L.pop();
        }
    }else{
        R.push(x);
        if(R.size()>L.size()){
            L.push(R.top());R.pop();
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n<=3){
            vector<ll> v;
            for(int i=1;i<=n;i++)v.push_back(a[i]);
            sort(v.begin(),v.end());
            v.erase(unique(v.begin(),v.end()),v.end());
            ll best=1e18;
            vector<ll> curb(n),bestb;
            int sz=v.size();
            function<void(int)> dfs=[&](int p){
                if(p==n){
                    ll sum=0;
                    for(int i=1;i<n;i++)sum+=abs(a[i]-a[i+1]);
                    for(int i=0;i<n;i++){
                        if(i)sum+=abs(curb[i]-curb[i-1]);
                        sum+=abs(curb[i]-a[i+1]);
                    }
                    if(sum<best){
                        best=sum;
                        bestb=curb;
                    }
                    return;
                }
                for(int i=0;i<sz;i++){
                    curb[p]=v[i];
                    dfs(p+1);
                }
            };
            dfs(0);
            for(int i=0;i<n;i++)cout<<bestb[i]<<" \n"[i==n-1];
            continue;
        }
        while(!L.empty())L.pop();
        while(!R.empty())R.pop();
        ans=0;
        L.push(a[1]);R.push(a[1]);
        for(int i=2;i<=n;i++){
            ll l=L.top()+(i-1);
            ll r=R.top()-(i-1);
            if(a[i]<l){
                ans+=l-a[i];
                L.pop();
                R.push(l-(i-1));
                L.push(a[i]);L.push(a[i]);
            }else if(a[i]>r){
                ans+=a[i]-r;
                R.pop();
                L.push(r+(i-1));
                R.push(a[i]);R.push(a[i]);
            }else{
                L.push(a[i]);R.push(a[i]);
            }
        }
        b[n]=L.top()+n;
        for(int i=n-1;i>=1;i--){
            ll x=b[i+1];
            ll cost=1e18,by=0;
            for(ll d=-2;d<=2;d++){
                ll y=x+d;
                if(y<1||y>2000000000)continue;
                ll cur=abs(y-x)+abs(y-a[i]);
                if(cur<cost){
                    cost=cur;by=y;
                }
            }
            b[i]=by;
        }
        for(int i=1;i<=n;i++)cout<<b[i]<<" \n"[i==n];
    }
    return 0;
}