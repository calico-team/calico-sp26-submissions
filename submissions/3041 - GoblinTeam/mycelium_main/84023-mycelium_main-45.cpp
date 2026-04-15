#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll solve(ll XG,ll YG,ll XM,ll YM){
    ll Ua=XG+YG,Va=XG-YG,Ub=XM+YM,Vb=XM-YM;
    ll dU=Ub-Ua,dV=Vb-Va;
    auto sgn=[](ll x){return x<0?-1:x>0?1:0;};
    ll ans=1;
    for(int su=-1;su<=1;su+=2){
        for(int sv=-1;sv<=1;sv+=2){
        ll u0=su*dU,v0=sv*dV;
        if(u0<0||v0<0)continue;
        ll U=u0,V=v0;
        ll P=(U+V)/2,Q=(U-V)/2;
        if(P<0||Q<0)continue;
        if(P<Q)swap(P,Q);
        auto f=[](ll a,ll b,ll c,ll d){
            return ((c*7<=b*2)||(a*7<=d*2));
        };
        ll cnt=0;
        for(ll p=0;p<=P+Q;++p){
            ll lq=-Q,rq=Q;
            while(lq<=rq){
                ll q=(lq+rq)/2;
                ll lp=abs(p-P),lq_=abs(q-Q);
                ll rp=p,rq_=abs(q);
                if(7*max(lp,lq_)<2*max(rp,rq_)){
                    cnt++;
                    break;
                }
                if(7*max(lp,lq_)>=2*max(rp,rq_)){
                    if(p>=P)
                    rq=q-1;
                    else lq=q+1;
                }
            }
        }
        ans+=cnt;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll XG,YG,XM,YM;
        cin>>XG>>YG>>XM>>YM;
        cout<<solve(XG,YG,XM,YM)<<endl;
    }
}