#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll g(ll a,ll b,ll&x,ll&y)
{
    if(!b)
    {
        x=1;y=0;return a;
    }
    ll d=g(b,a % b,y,x);
    y-=a/b*x;
    return d;
}
bool f(ll a,ll b,ll m,ll&r,ll&d)
{
    ll x ,y;
    ll h= g(a,m,x,y);
    if(b %h)return 0;
    d=m/h;
    r=(x %d *(b/h%d))%d;
    if(r<0)r+=d;
    return 1;
}

void solve()
{
    ll k,n,m,p,q;
    cin>>k>>n>>m>>p>>q;
    vector<ll> x(k),y(k);
    for(int i=0;i<k;i++)
    {
        cin>>x[i]>>y[i];
    }
    ll x0 = x[0],y0 =y[0];
    ll v=-1;
    int z=-1;
    for(int i=0;i<k;i++)
    {
        ll r1 ,m1,r2,m2;
        ll dx=(x[i]-x0)%n;
        if(dx<0)dx+=n;
        ll dy=(y [i]-y0)%m;
        if(dy<0)dy+=m;
        if(!f(q,dx,n,r1,m1))continue;
        if (!f(p,dy,m,r2,m2))continue;
        ll k2,d2,r,d;
        if(!f(m1,r2-r1,m2,k2,d2))continue;
        d=m1*d2;
        r= m1*k2+r1;
        if(r==0)r=d;
        if(v==-1||r<v)
        {
            v=r;
            z=i;
        }
    }
    cout<<z<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}