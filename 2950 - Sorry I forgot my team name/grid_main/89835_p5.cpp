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
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll N;
	cin >> N;
	while(N--) {
		ll n;
		cin >> n;
		vl w;
		for(int i=0;i<n;i++) {
			ll t;
			cin >> t;
			w.push_back(t);
		}
		vl ans;
		ll ansv = INFL;
		{
			for(int rev=0;rev<2;rev++) {
				vector<pl> ps;
				for(int i=0;i<n;i++) {
					if(ps.empty() || w[i] >= ps.back().first) {
						ps.emplace_back(w[i],i);
					} else {
						ll len = 1;
						vl ord;
						ord.push_back(w[i]);
					}
				}

				reverse(w.begin(),w.end());
				reverse(ans.begin(),ans.end());
			}
		}
	}
}

