#include "bits/stdc++.h"

#define forR(p, q) for(int p = 0; p < (q); ++p)
#define forO(p, q) for(int p = 1; p <= (q); ++p)
#define REP(p, a, b) for(int p = a; p < (b); ++p)
#define rep(p, a, b) for(int p = a; p < (b); ++p)
#define boost() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
vi range(int st, int ed) { vi ret(ed - st); for(int i = st; i < ed; ++i) ret[i-st] = i; return ret;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<> urd(0.0, 1.0);
typedef set<int> si;
typedef vector<ll> vll;
typedef set<ll> sll;
template<typename T> auto sz(T&& i) { return i.size(); }
#define all(x) x.begin(), x.end()
struct pii{int a, b;};
struct pll{ll a, b;};
#pragma GCC optimize("Ofast")
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
template<class T>T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}
typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
	if (sz(pts) <= 1) return pts;
	sort(all(pts));
	vector<P> h(sz(pts)+1);
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(all(pts)))
		for (P p : pts) {
			while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

#ifdef DBG
const bool DEBUG = true;
#else
const bool DEBUG = false;
#endif

struct debOut {
    template<typename T> debOut &operator<<(T &&i) {
        if(DEBUG) {
            cout << std::forward<T>(i);
        }
        return *this;
    }
    // Handle std::endl and other ostream manipulators
    debOut &operator<<(std::ostream& (*manip)(std::ostream&)) {
        if (DEBUG) {
            std::cout << manip;
        }
        return *this;
    }
} dout;
template<typename T, typename U> struct pi {
    T a;
    U b;
};
template<typename T> using vec = vector<T>;

const int MN = 510;
const int OFF = 255;

struct Solver {
int cur[MN][MN];
vec<pii> gch, mch;
Solver() {}
void reset() {
	forR(i, MN) forR(j, MN) {
		cur[i][j] = 0;
	}
}
void tick(int ct) {
	if(ct % 2 == 0) {
		vec<pii> newG;
		for(auto [i, j] : gch) {
			assert(cur[i][j] == 1);
			if(cur[i-1][j] == 0) {
				cur[i-1][j] = 1;
				newG.push_back({i-1, j});
			}
			if(cur[i][j-1] == 0) {
				cur[i][j-1] = 1;
				newG.push_back({i, j-1});
			}
			if(cur[i+1][j] == 0) {
				cur[i+1][j] = 1;
				newG.push_back({i+1, j});
			}
			if(cur[i][j+1] == 0) {
				cur[i][j+1] = 1;
				newG.push_back({i, j+1});
			}
		}
		gch.swap(newG);
	}
	if(ct % 7 == 0) {
		vec<pii> newM;
		for(auto [i, j] : mch) {
			if(cur[i-1][j] == 0) {
				cur[i-1][j] = 2;
				newM.push_back({i-1, j});
			}
			if(cur[i][j-1] == 0) {
				cur[i][j-1] = 2;
				newM.push_back({i, j-1});
			}
			if(cur[i+1][j] == 0) {
				cur[i+1][j] = 2;
				newM.push_back({i+1, j});
			}
			if(cur[i][j+1] == 0) {
				cur[i][j+1] = 2;
				newM.push_back({i, j+1});
			}
		}
		mch.swap(newM);
	}
}
void solve() {
	int xg, yg, xm, ym;
	cin >> xg >> yg >> xm >> ym;
	xg += OFF; yg += OFF; xm += OFF; ym += OFF;
	reset();
	cur[xg][yg] = 1;
	cur[xm][ym] = 2;
	gch.push_back({xg, yg});
	mch.push_back({xm, ym});

	int cntM = 1;
	for(int ct = 2; ; ++ct) {
		tick(ct);
		int curM = 0;
		forR(i, MN) forR(j, MN) {
			if(cur[i][j] == 2) {
				++curM;
			}
		}

		if(ct % 7 == 0 && curM == cntM) {
			break;
		}
		cntM = curM;
	}
	cout << cntM << '\n';
}
};

signed main() {
    boost();
	int t; cin >> t;
	while(t--) {
		Solver solver;
		solver.solve();
	}
}