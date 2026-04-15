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
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll N;
	cin >> N;
	while(N--) {
		ll n,m;
		cin >> n >> m;
		vvi g(n,vi(m,-1));
		vvi gv(n*m*3);
		int SO = n*m;
		int TO = n*m+1;
		int TV = n*m+2;
		int ru = 0;
		for(int i=0;i<n;i++) {
			string s;
			cin >> s;
			for(int j=0;j<m;j++) {
				char ch = s[j];
				switch(ch) {
					case '>': {
						g[i][j] = 0;break;
					}
					case 'v': {
						g[i][j] = 1;break;
					}
					case '<': {
						g[i][j] = 2;break;
					}
					case '^': {
						g[i][j] = 3;break;
					}
					case 'S': {
						g[i][j] = 4;break;
					}
					case 'X': {
						g[i][j] = 5;break;
					}
				}
			}
		}
		vi end(gv.size());
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				int u = i*m+j;
				vi nos;
				for(int d=0;d<4;d++) {
					int r = i+dr[d];
					int c = j+dc[d];
					int ad = -1;
					if(r < 0 || r >= n) {
						ad = TO;
					} else if(c < 0 || c >= m) {
						ad = TO;
					} else {
						ad = r*m+c;
					}
					nos.push_back(ad);
				}
				if(g[i][j] < 0) {continue;}
				if(g[i][j] < 4) {
					assert(g[i][j] < nos.size());
					int dv = nos[g[i][j]];
					assert(u < gv.size());
					gv[u].push_back(dv);
					end[dv]++;
				} else if(g[i][j] == 4) {
					for(int d=0;d<4;d++) {
						int r = i+dr[d];
						int c = j+dc[d];
						int ad = -1;
						if(r < 0 || r >= n) {
							continue;
						}
						if(c < 0 || c >= m) {
							continue;
						}
						if(g[r][c] == -1) {continue;}
						if(g[r][c] != (d^2)) {
							ad = r*m+c;
							gv[u].push_back(ad);
					end[ad]++;
						}
					}
				} else {
					gv[u].push_back(TV);
					end[TV]++;
				}
			}
		}
		vector<F> wals(gv.size());
		queue<int> q;
		q.push(0);
		wals[0] = F(1,1);
		while(!q.empty()) {
			int u = q.front();q.pop();
			F adv = wals[u];
			if(gv[u].size() == 0) {continue;}
			adv.d *= gv[u].size();
			adv.simp();
			for(const auto& v: gv[u]) {
				wals[v] = wals[v]+adv;
				end[v]--;
				if(end[v] == 0) {
					q.push(v);
				}
			}
		}
		F ans = wals[TO];
		cout << ans.n << " " << ans.d << '\n';
	}
}

