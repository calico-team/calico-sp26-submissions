#include <bits/stdc++.h>

using namespace std;

/////////////////////// MACROS ////////////////////////////////////////////
using ll = long long;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vc = vector<char>;
using vpi = vector<pi>;
using vpl = vector<pl>;

#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
tcTU> using PR = pair<T,U>;
tcTU> using umap = unordered_map<T, U>;
tcT> using uset = unordered_set<T>;
tcT> using mset = multiset<T>;

#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define ppb pop_back()
#define ppf pop_front()
#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

// LOOPS
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_, a)
#define each(a,x) for (auto& a: x)

/////////////////////// IMPORANT VARS /////////////////////////////////////

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INFL = ll(3e18)+10;
const int INF = int(1e9)+10;
const ld PI = acos((ld)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
tcT> using pqg = priority_queue<T,vector<T>,greater<T>>;
tcT> using pql = priority_queue<T,vector<T>,less<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define nl '\n'

constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { 
	return x == 0 ? 0 : 31-__builtin_clz(x); }
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }
 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
 
tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
 
tcTU> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find last index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set


// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// tcT> using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// #define ook order_of_key
// #define fbo find_by_order

// struct chash { 
// 	const uint64_t C = ll(2e18*PI)+71;
// 	const int RANDOM = rng();
// 	ll operator()(ll x) const {
// 		return __builtin_bswap64((x^RANDOM)*C); }
// };

// struct splitmix64_hash {
// 	static uint64_t splitmix64(uint64_t x) {
// 		// http://xorshift.di.unimi.it/splitmix64.c
// 		x += 0x9e3779b97f4a7c15;
// 		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// 		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// 		return x ^ (x >> 31);
// 	}

// 	size_t operator()(uint64_t x) const {
// 		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
// 		return splitmix64(x + FIXED_RANDOM);
// 	}
// };


// template<class K,class V> using um = unordered_map<K,V,chash>;
// template<class K,class V> using ht = gp_hash_table<K,V,chash>;
// template<class K,class V> V get(ht<K,V>& u, K x) {
// 	auto it = u.find(x); return it == end(u) ? 0 : it->s; }

/////////////////////// OUPUT /////////////////////////////////////////////
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) {
	#ifdef LOCAL
		return b ? "true" : "false";
	#else
		return ts((int)b);
	#endif
}
tcTU> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")";
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}

tcTU> str ts(V<pair<T, U>> v) {
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;
	#endif
}

tcT> str ts(T v) {
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

	#endif
}

///////////////////////// DEBUG ///////////////////////////////////////////
#define tcTUU tcT, class ...U
void DBG() { cerr << "]" << "\e[0m" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef LOCAL
	#define dbg(...) cerr << "\e[1m" << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__);
	#define asrt(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define asrt(...) 0
#endif	

///////////////////////// FILE I/O ////////////////////////////////////////
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setPrec() { cout << fixed << setprecision(15); }
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s = "") {
	unsyncIO(); setPrec();
	#ifndef LOCAL	
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for USACO
	#endif
}

///////////////////////// TEMPLATE ABOVE //////////////////////////////////

// REMEMBER
// - Don't Focus On Only One Approach
// - Read And Understand Problem Fully
// - Think Of Edges Cases
// - Implement Carefully
// - Always Check For Overflows
// - Reset Global Variables
// - Look At The Bigger Picture
// - Don't Get Discouraged, You Can Pull It Back

void solve() {
	int N; cin >> N; 

	vi A(N); each(x, A) cin >> x;

	vi B = A;
	FOR(i, 1, N - 1) if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
		B[i] = max(A[i - 1], A[i + 1]);
	}

	each(x, B) cout << x << " ";
	cout << nl;
}

int main() {
	setIO(); 

	int TT = 1;
	cin >> TT;

	rep(TT) solve();
	
	exit(0-0);
}
