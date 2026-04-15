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
string sord = ".>v<^SX";
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll N;
	cin >> N;
	while(N--) {
		ll p,a,b;
		cin >> p >> a >> b;
		vl res;
		vl bos;
		for(int i=0;i<a;i++) {
			bos.push_back(2);
		}
		for(int i=0;i<b;i++) {
			bos.push_back(3);
		}
		res.assign(bos.size(),0);
		res.back() = p;
		for(int i=res.size()-1;i>0;i--) {
			ll rv = res[i]/bos[i];
			res[i] %= bos[i];
			res[i-1] += rv;
		}
		const int A = 6;
		vvi g(3*(a+b)+6,vi(A));
		g[0][0] = 2;
		g[1][0] = 1;
		g[1][1] = 1;
		int lim = g.size();
		for(int i=0;i<bos.size();i++) {
			int r = 3*i+1;
			int c = 2;
			g[r][c] = 5;
			if(bos[i] == 2) {
				g[r][c+1] = 1;
				g[r][c+2] = 6;
				g[r+1][c] = 3;
				if(res[i] > 0) {
					g[r][c+2] = 1;
					lim = min(lim,r);
				}
			} else {
				g[r-1][c] = 1;
				g[r-1][c+1] = 6;
				g[r][c+1] = 1;
				g[r][c+2] = 6;
				g[r+1][c] = 3;
				if(res[i] > 0) {
					g[r-1][c+1] = g[r-1][c+2] = 1;
					lim = min(lim,r);
				}
				if(res[i] > 1) {
					g[r][c+2] = 1;
					lim = min(lim,r);
				}
			}
			if(i+1 < bos.size()) {
				g[r+1][c-1] = 2;
				g[r+2][c-1] = 2;
				g[r+3][c-1] = 1;
			} else {
				g[r+1][c-1] = 6;
			}
		}
		for(int i=lim;i<g.size();i++) {
			g[i][5] = 2;
		}
		cout << g.size() << " " << A << '\n';
		for(int i=0;i<g.size();i++) {
			for(int j=0;j<g[i].size();j++) {
				cout << sord[g[i][j]];
			}
			cout << '\n';
		}
	}
}

