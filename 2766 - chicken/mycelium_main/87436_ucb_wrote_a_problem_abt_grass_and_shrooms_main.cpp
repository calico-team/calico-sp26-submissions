#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

__int128_t fs(ll n,ll m,ll a,ll b)
{
    __int128_t r=0;
    while(1)
    {
        if (a >=m)
        {
            r+=(__int128_t)(n-1)*n*(a/m)/2;
            a%=m;
        }
        if(b>=m)
        {
            r+= (__int128_t)n* (b/m);
            b%=m;
        }
        ll y=(ll)((__int128_t)a*n+b);
        if(y<m) break;
        n=y/m;
        b=y% m;
        swap(m,a);
    }
    return r;
}
ll sm(ll c,ll a,ll b,ll l,ll r)
{
    if (l>r)return 0;
    if(c-a*r<0)return 0;
    ll n =r-l+1;
    ll k=c-a *r;
    return (ll)fs(n, b,a, k);
}
ll ct(ll c,ll a,ll b,ll l,ll r)
{
    if(l> r)return 0;
    return r-l+1 +sm(c,a,b,l,r);
}
ll cq(ll p,ll q)
{
    if(p<= 0||q<=0)return 0;
    ll x=min((p -1)/9,(q-1)/5);
    auto f=
    [&](ll i)
    {
        return (p-1-9*i)/5<=(q-1-5*i)/9;
    };
    if(f (0))
    {
        return x+1+sm(p-1,9,5,0,x);
    }
    ll l=0,r=x+1;
    while(l<r)
    {
        ll m=(l+r)/2;
        if(f (m))r=m;
        else l=m+1;
    }
    ll t=l;
    ll s= 0;
    if(t >0)s+=t+sm(q-1,5,9,0,t-1);
    if(t<= x)s+=x-t+1+ sm(p-1,9,5,t,x);
    return s;
}
void solve()
{
    int t;
    cin>> t;
    while(t--)
    {
        ll x1,y1,x2 ,y2;
        cin >>x1>>y1>>x2>>y2;
        
        ll a=llabs(x2 -x1);
        ll b=llabs (y2-y1);
        if(a>b)swap(a,b);
        ll d=a+b;
        ll k=(2*d-1) /9;
        ll e =(2*d-1)/5;
        ll w=min(a,k);
        if(b>a)
        {
            ll z=(2*(b-a)-1)/5;
            if(z>w)w=z;
        }
        ll h=0;
        if(w>=a)h=w-a+1;
        ll n=(2*d+4 *h-1)/5;
        ll an=0;
        ll  p=2*d+4*(e+1);
        ll q=2*d+4*(n+1);
        an+=cq(p ,q);
        an+=ct(2*d-1,9,5,1,k);
        an+=ct (2*d-1,9,5,1,min(a,k));
        if(b>a)
        {
            ll r= (2*(b-a)-1)/5;
            if(r>a )
            {
                ll m=r-a;
                an+=m*(m+1)/2;

                ll c=2*(b-a)-1;
                ll y=(c-5*(a+1))/9;
                if (y>=1)
                {
                    an+=sm  (c,9,5,1,y)-a *y;
                }
            }
        }
        ll m=k;
        ll s=min (a,m-1);
        if(s>0)

        {
            an +=s*m-s*(s+1)/ 2;
        }
        cout <<an<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}