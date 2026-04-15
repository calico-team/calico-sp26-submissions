#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

long long egcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    long long x1,y1, g=egcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}

long long minv(long long a,long long mod)
{
    long long x,y, g=egcd(a,mod,x,y);
    if(g!=1)return -1;
    x%=mod;
    if(x<0)x+=mod;
    return x;
}

bool combine(long long a1,long long m1,long long a2,long long m2,long long &res,long long &lm)
{
    long long g=gcd(m1,m2), df=a2-a1;
    if(df%g!=0)return false;
    long long m1d=m1/g, m2d=m2/g, dd=df/g, x=0;
    dd%=m2d;
    if(dd<0)dd+=m2d;
    if(m2d>1)
    {
        long long inv=minv(m1d%m2d,m2d);
        x=(dd*inv)%m2d;
    }
    long long lv=m1*m2d, val=(m1*x+a1)%lv;
    if(val<0)val+=lv;
    res=val;
    lm=lv;
    return true;
}

void solve()
{
    long long k, n,m,p,q;
    cin>>k>>n>>m>>p>>q;
    vector<pair<long long,long long> > a(k);
    for(int i=0;i<k;i++)cin>>a[i].first>>a[i].second;
    long long sx=a[0].first, sy=a[0].second, gx=gcd(q,n), mx=n/gx, bx=q/gx, ix=0;
    if(mx>1)
    {
        long long tmp=bx%mx;
        if(tmp<0)tmp+=mx;
        ix=minv(tmp,mx);
    }
    long long gy=gcd(p,m), my=m/gy, by=p/gy, iy=0;
    if(my>1)
    {
        long long tmp=by%my;
        if(tmp<0)tmp+=my;
        iy=minv(tmp,my);
    }
    long long ok=-1;
    int ans=-1;
    for(int i=0;i<k;i++)
    {
        long long dx=a[i].first-sx;
        dx%=n;
        if(dx<0)dx+=n;
        if(dx%gx!=0)continue;
        long long dy=a[i].second-sy;
        dy%=m;
        if(dy<0)dy+=m;
        if(dy%gy!=0)continue;
        long long t1=0;
        if(mx>1)
        {
            long long dxu=(dx/gx)%mx;
            t1=(dxu*ix)%mx;
        }
        long long t2=0;
        if(my>1)
        {
            long long dyu=(dy/gy)%my;
            t2=(dyu*iy)%my;
        }
        long long res=0, lm=0;
        if(!combine(t1,mx,t2,my,res,lm))continue;
        if(res==0)res=lm;
        if(ok==-1||res<ok)
        {
            ok=res;
            ans=i;
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
