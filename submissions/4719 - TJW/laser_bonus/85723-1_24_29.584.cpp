#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
ll gcd(ll a,ll b)
{
	while(b)
	{
		ll t = a%b;
		a = b;
		b = t;
	}
	return a;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll x1,y1;
	ll g = exgcd(b,a%b,x1,y1);
	x  =y1;
	y = x1-a/b*y1;
	return g;
}
ll inv(ll a,ll m)
{
	ll x,y;
	exgcd(a,m,x,y);
	x %= m;
	if(x<0)
	{
		x += m;
	}
	return x;
}
ll crt(ll a1,ll m1,ll a2,ll m2)
{
	if(m1==1)
	{
		return a2 % m2;
	}
	if(m2==1)
	{
		return a1 % m1;
	}
	ll x,y;
	ll g = exgcd(m1,m2,x,y);
	ll d = a2 - a1;
	if(d%g!=0)
	{
		return -1;
	}
	ll mod = m2 / g;
	ll t=((__int128)(d/g) * inv(m1/g,mod)) % mod;
	if(t<0)
	{
		t += mod;
	}
	ll l = m1 / g * m2;
	ll r = (a1 + (__int128)m1 * t) % l;
	if(r<0)
	{
		r += l;
	}
	return r;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k;
		ll n,m,p,q;
		cin>>k>>n>>m>>p>>q;
		vector<ll> x(k),y(k);
		for(int i=0;i<k;i++)
		{
			cin>>x[i]>>y[i];
		}
		ll x0 = x[0],y0 = y[0];
		ll gx = gcd(q,n);
		ll gy = gcd(p,m);
		ll nx = n / gx;
		ll my = m / gy;
		ll iq = inv(q/gx,nx);
		ll ip = inv(p/gy,my);
		ll per = nx / gcd(nx,my) * my;
		ll bt = (1LL<<62);
		//Ahhhhhhhhhhhhhhhhhh~~~~~~~~~~~
		//Looking sooooooooooooooooooo good!
		int ans = -1;
		for(int i=0;i<k;i++)
		{
			ll dx = (x[i]-x0) % n;
			ll dy = (y[i]-y0) % m;
			if(dx<0)
			{
				dx += n;
			}
			if(dy<0)
			{
				dy += m;
			}
			if(dx%gx!=0||dy%gy!=0)
			{
				continue;
			}
			ll tx = ((__int128)(dx/gx) * iq) % nx;
			ll ty = ((__int128)(dy/gy) * ip) % my;
			ll tm = crt(tx,nx,ty,my);
			if(tm==-1)
			{
				continue;
			}
			if(i==0&&tm==0)
			{
				tm = per;
			}
			if(tm<bt)
			{
				bt = tm;
				ans = i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
