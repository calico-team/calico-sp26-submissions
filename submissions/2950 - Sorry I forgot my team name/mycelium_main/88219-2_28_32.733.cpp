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
ll gcd(ll a, ll b) {
	if(a == 0) return b;
	if(b == 0) return a;
	return gcd(b,a%b);
}
struct F {
	ll n,d;
	F(): n(0),d(1) {
	}
	void simp() {
		ll g = gcd(n,d);
		n /= g;
		d /= g;
	}
	F(ll n, ll d): n(n), d(d) {}
	F operator+(const F& ot) const {
		F ans(n*ot.d+d*ot.n,d*ot.d);
		ans.simp();
		return ans;
	}
};
// R D L U
const int dr[4] = {0,1,0,-1};
const int dc[4] = {1,0,-1,0};
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
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll N;
	cin >> N;
	while(N--) {
		ll ax,ay,bx,by;
		cin >> ax >> ay >> bx >> by;
		P pa(ax,ay),pb(bx,by);
		map<P,int> gos;
		gos[pa] = 0;
		gos[pb] = 1;
		set<P> mes;
		mes.insert(pb);
		int rv = 1;
		while(1) {
			map<P,int> nx;
			for(const auto& [p,v]: gos) {
				if(v == 1 && rv%7 == 0) {
					for(int d=0;d<4;d++) {
						P np = p;
						np.x += dr[d];
						np.y += dc[d];
						if(!gos.count(np) && !nx.count(np)) {
							nx[np] = v;
						}
					}
				}
				if(v == 0 && rv%2 == 0) {
					for(int d=0;d<4;d++) {
						P np = p;
						np.x += dr[d];
						np.y += dc[d];
						if(!gos.count(np)) {
							nx[np] = v;
						}
					}
				}
			}
			int kt = 0;
			for(const auto& [p, v]: nx) {
				gos[p] = v;
				if(v == 1) {
					kt++;
					mes.insert(p);
				}
			}
			if(rv%7 == 0 && kt == 0) {
				break;
			}
			rv++;
		}
		cout << mes.size() << '\n';
	}
}
