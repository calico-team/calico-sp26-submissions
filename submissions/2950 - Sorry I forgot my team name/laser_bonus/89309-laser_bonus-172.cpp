#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fore(b,c) for(int val0=b;val0<c;val0++)
#define forr(k,c,s) for(int k=c;k<s;k++)
#define pb push_back
#define mmp make_pair
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T, typename S>
using omap = tree<T,S,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<vii> al;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
const int INF = 1e9;
const ll INFL = 1LL<<61;
template<class T> struct Point {
	typedef Point P;
	T x,y;
	explicit Point(T x=0, T y=0): x(x),y(y) {}
	bool operator<(P p) const {
		return tie(x,y) < tie(p.x,p.y);
	}
	bool operator==(P p) const {
		return tie(x,y) == tie(p.x,p.y);
	}
	P operator+(P p) const {return P(x+p.x,y+p.y);}
	P operator-(P p) const {return P(x-p.x,y-p.y);}
	P operator*(T d) const {return P(x*d,y*d);}
	P operator/(T d) const {return P(x/d,y/d);}
	T dot(P p) const {return x*p.x+y*p.y;}
	T cross(P p) const {
		return x*p.y-y*p.x;
	}
	T cross(P a, P b) const {
		return (a-*this).cross(b-*this);
	}
	T dist2() const {return x*x+y*y;}
	double dist() const {return sqrt((double)dist2());}
	double angle() const {return atan2(y,x);}
	P unit() const {return *this/dist();}
	P perp() const {return P(-y,x);}
	P normal() const {return perp().unit();}
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
	}
};
using P = Point<ll>;
ll gcd(ll a, ll b) {
	if(a == 0) return b;
	if(b == 0) return a;
	return gcd(b,a%b);
}
ll lcm(ll n, ll m) {
	return n/gcd(n,m)*m;
}
pl eul(ll a, ll b, ll s, ll t, ll u, ll v) {
	if(a == 0) {return pl(u,v);}
	if(b == 0) {return pl(s,t);}
	return eul(b,a%b,u,v,s-(a/b)*u,t-(a/b)*v);
}
ll chr(ll a, ll n, ll b, ll m) {
	ll g = gcd(n,m);
	if(a%g != b%g) {return -1;}
	ll ad = a%g;
	a /= g;n /= g;b /= g;m /= g;
	pl pv = eul(n,m,1,0,0,1);
	ll nx = pv.first*n;
	ll mx = pv.second*m;
	ll av = nx*b+mx*a;
	av = ((av%(n*m))+n*m)%(n*m);
	return av*g+ad;
}

int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll N;
	cin >> N;
	while(N--) {
		ll ko,n,m,po,qo;
		cin >> ko >> n >> m >> po >> qo;
		swap(po,qo);
		vector<P> pos;
		vl wos;
		for(int i=0;i<ko;i++) {
			ll x,y;
			cin >> x >> y;
			pos.emplace_back(x,y);
		}
		{
			vector<P> npos;
			for(int i=0;i<ko;i++) {
				npos.push_back(pos[i]-pos[0]);
				npos[i].x = ((npos[i].x%n)+n)%n;
				npos[i].y = ((npos[i].y%m)+m)%m;
			}
			swap(npos,pos);
		}

		ll gn = gcd(po,n);
		ll pv = po/gn;

		ll gm = gcd(qo,m);
		ll qv = qo/gm;

		ll nv = n/gn;
		ll mv = m/gm;

		vl prv(nv);
		vl qrv(mv);
		{
			for(int i=0;i<nv;i++) {
				prv[i*pv%nv] = i;
			}
			for(int i=0;i<mv;i++) {
				qrv[i*qv%mv] = i;
			}
		}

		ll ans = 0;
		ll ansv = lcm(nv,mv);
		for(int i=1;i<pos.size();i++) {
			if(pos[i].x%gn) {continue;}
			if(pos[i].y%gm) {continue;}
			ll x = pos[i].x/gn;
			ll y = pos[i].y/gm;
			ll xv = prv[x];
			ll yv = qrv[y];
			ll av = chr(xv,nv,yv,mv);
			if(av == -1) {continue;}
			if(av < ansv) {
				ansv = av;
				ans = i;
			}
		}
		cout << ans << '\n';
	}
}

