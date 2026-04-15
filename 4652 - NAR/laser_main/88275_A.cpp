/***********Template Starts Here***********/
//#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<deque>
#include<functional>
#include<string>
#include<iostream>
#include<cctype>
#include<set>
#include<climits>
#include<iomanip>
#include<cassert>
#include<sstream>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hevlongo\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountvlong
#define RIGHTMOST __builtin_ctzvlong
#define LEFTMOST(x) (63-__builtin_clzvlong((x)))
#define MP make_pair
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define Avlong(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((vlong)(x).size())
#define NORM(x) if(x>=mod)x-=mod;
#define MOD(x,y) (((x)*(y))%mod)
#define ODD(x) (((x)&1)==0?(0):(1))

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < vlong, vlong > pvlong;
typedef vector<pvlong> vvlong;
typedef vector<vlong> vl;

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
     #define bug printf("%d\n",__LINE__);

#else
    #define debug(args...)  // Just strip off avlong debug tokens
    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    x %= m;
    if ( x < 0 ) x += m; //modInv is never negative
    return x;
}

inline vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}

vlong exp(vlong x, vlong n, vlong m) {
	x %= m;  // note: m * m must be less than 2^63 to avoid vlong overflow
	vlong res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

class ChineseRemainderTheorem {
    typedef long long vlong;
    typedef pair<vlong,vlong> pvlong;

    /** CRT Equations stored as pairs of vector. See addEqation()*/
    vector<pvlong> equations;

public:
    void clear() {
        equations.clear();
    }

    /** Add equation of the form x = r (mod m)*/
    void addEquation( vlong r, vlong m ) {
        equations.push_back({r, m});
    }
    pvlong solve() {
        if (equations.size() == 0) return {-1,-1}; /// No equations to solve

        vlong a1 = equations[0].first;
        vlong m1 = equations[0].second;
        a1 %= m1;
        /** Initiavlongy x = a_0 (mod m_0)*/

        /** Merge the solution with remaining equations */
        for ( int i = 1; i < equations.size(); i++ ) {
            vlong a2 = equations[i].first;
            vlong m2 = equations[i].second;

            vlong g = __gcd(m1, m2);
            if ( a1 % g != a2 % g ) return {-1,-1}; /// Conflict in equations

            /** Merge the two equations*/
            vlong p, q;
            ext_gcd(m1/g, m2/g, &p, &q);

            vlong mod = m1 / g * m2;
            vlong x = ( (__int128)a1 * (m2/g) % mod *q % mod + (__int128)a2 * (m1/g) % mod * p % mod ) % mod;

            /** Merged equation*/
            a1 = x;
            if ( a1 < 0 ) a1 += mod;
            m1 = mod;
        }
        return {a1, m1};
    }
};

/** 
 * Find the index of the first asteroid hit by the laser.
 * 		
 * K: Number of asteroids
 * N, M: Bounds for x- and y-coordinates
 * P, Q: Laser movement (P along y-axis, Q along x-axis)
 * X: List of x-coordinates of asteroids
 * Y: List of y-coordinates of asteroids
 */

vlong solve(vlong K, vlong N, vlong M, vlong P, vlong Q, vector<vlong> X, vector<vlong> Y) {
	vlong x = X[0]; vlong y = Y[0];
	for (vlong i = 0; i < K; i++) {
		X[i] = ((X[i] - x) + N)%N;
		Y[i] = (Y[i] - y + M)%M; 
	}
	vlong g1 = gcd(N, Q);
	vlong g2 = gcd(M, P);
	vlong n2 = N/g1; vlong m2 = M/g2; vlong q2 = Q/g1; vlong p2 = P/g2;
	vlong R = 1e18; vlong m = -1;
	for (int i = 0; i < K; i++) {
		vlong x1 = X[i]; vlong y1 = Y[i];
		if ((x1%g1 != 0) || (y1%g2 != 0)) {
			continue;
		} else {
			vlong x2 = x1/g1;
			vlong y2 = y1/g2;
            ChineseRemainderTheorem CRT2;
			vlong x3 = (x2 * modInv(q2, n2))%n2;
			vlong y3 = (y2 * modInv(p2, m2))%m2; // wrong cuz not prime
			vlong g3 = gcd(n2, m2);
			if ((x3-y3)%g3 != 0) {continue;}
            ChineseRemainderTheorem CRT;
            CRT.addEquation(x3, n2);
            CRT.addEquation(y3, m2);
            pvlong t = CRT.solve();
			// vlong d = (x3-y3)/g3;
			// vlong n3 = n2/g3; vlong m3 = m2/g3;
			// vlong u1 = ((-d)*exp(n3, m3-2, m3))%m3;
			// vlong u2 = ((d)*exp(m3, n3-2, n3))%n3;
			// if (u1 == 0 && x3 == 0) u1 = m3;
			// vlong r = (vlong)n2*(vlong)u1 + (vlong)x3;
			// cout << "i, r: " << i << ", " << r << "\n";
			if (t.first < R && t.first != 0) {
				R = t.first;
				m = i;
			}
		}	
	}
    if (m2*n2 < R) {
        m = 0;
    }
	return m;
}


int main() {
	vlong T; cin >> T;
	while (T--) {
		vlong K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
		vector<vlong> X(K), Y(K);
		for (int i = 0; i < K; i++) {
			vlong a, b; cin >> a >> b;
			X[i] = a;
			Y[i] = b;
		}
		cout << solve(K, N, M, P, Q, X, Y) << endl;
	}
	return 0;
}