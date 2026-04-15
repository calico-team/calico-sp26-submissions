#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int T,n;
ll a[N],b[N];
priority_queue<ll> L;
priority_queue<ll,vector<ll>,greater<ll>> R;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        while(!L.empty())L.pop();
        while(!R.empty())R.pop();
        L.push(a[1]);R.push(a[1]);
        for(int i=2;i<=n;i++){
            ll l=L.top()+(i-1);
            ll r=R.top()-(i-1);
            if(a[i]<l){
                L.pop();
                R.push(l-(i-1));
                L.push(a[i]);L.push(a[i]);
            }else if(a[i]>r){
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
            ll cost=4e18,by=0;
            vector<ll> c={a[i],a[i]-1,a[i]+1,x,x-1,x+1};
            sort(c.begin(),c.end());
            c.erase(unique(c.begin(),c.end()),c.end());
            for(ll y:c){
                if(y<1||y>2000000000)continue;
                ll cur=abs(y-x)+abs(y-a[i]);
                if(cur<cost||(cur==cost&&y<by)){
                    cost=cur;by=y;
                }
            }
            b[i]=by;
        }
        for(int i=1;i<=n;i++)cout<<b[i]<<" \n"[i==n];
    }
    return 0;
}