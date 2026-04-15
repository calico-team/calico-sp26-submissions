//  Some CALICO Problem
//  Fatespeaker
//  4/10/26


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

/** variables **/

using str = string;
using ll = long long;
using lls = unsigned long long int;
using i128 = __int128;
using vi = vector<int>;
using gi = vector<vector<int>>;
using vll = vector<long long>;
using vs = vector<string>;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vvll=vector<vector<ll>>;
using ull=unsigned long long;
using vd = vector<double>;
using dbl = double;
using flt = float;
using bl = bool;
using chr = char;
using vlls = vector<lls>;
using pdd = pair<double, double>;
using pldld = pair<long double, long double>;
#define prq priority_queue

/** keywords **/

#define f first
#define s second
#define qu queue
#define iset(T) tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
#define cont continue
#define br break
#define beg begin
#define rbeg rbegin
#define ret return
#define rev reverse
#define dist distance
#define tr true
#define fa false
#define pb push_back
#define pob pop_back
#define eb emplace_back
#define ins insert
#define fl ; cout.flush()
#define lfl cout.flush()
#define dec(PRESICION) fixed << setprecision(PRESICION)
#define gcd __gcd
#define lcm(a, b) ((a) * (b) / gcd(a, b))
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define even(x) (((x) & 1) == 0)
#define odd(x) (((x) & 1) == 1)
#define set_bit(x, i) ((x)|(1LL<<(i)))
#define clear_bit(x, i) ((x)&(~(1LL<<(i))))
#define toggle_bit(x, i) ((x)^(1LL<<(i)))
#define bit_val(x, i) (((x) >> (i)) & 1)
#define popcount(x) __builtin_popcountll(x)
#define trailing_zeros(x) __builtin_ctzll(x)
#define leading_zeros(x) __builtin_clzll(x)
#define sp <<' '<<
#define rnd(A, B) uniform_int_distribution<int>(A, B)(rng)

/** lines **/

#define sor(SORT) sort(SORT.begin(), SORT.end())
#define rsor(SORT) sort(SORT.rbegin(), SORT.end())
#define tc int TESTCASES; cin >> TESTCASES; while(TESTCASES--)
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define prepfio(IN, OUT) ifstream fin(IN); ofstream fout(OUT)
#define fillv(VECTOR, SIZE) for (int POPINDEX = 0; POPINDEX < SIZE; POPINDEX++) cin >> VECTOR[POPINDEX]
#define forl(LIMIT) for (int i = 0; i < LIMIT; i++)
#define jforl(LIMIT) for (int j = 0; j < LIMIT; j++)
#define cforl(VARIABLE, LIMIT) for (int VARIABLE = 0; VARIABLE < LIMIT; VARIABLE++)
#define rforl(LIMIT) for (int i = LIMIT; i >= 0; i--)
#define yn(YNFLAG) if (YNFLAG) cout << "YES\n"; else cout << "NO\n"
#define fill2d(GRID, COLUMNS, ROWS) for (int i = 0; i < ROWS; i++) for (int j = 0; j < COLUMNS; j++) cin >> GRID[i][j]

/**CUSTOM HASH**/
struct ch {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    //This is such a jolly hash
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



/** CONSTANTS **/

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll mod = 1000000007;
long double pi = 3.141592653589793238462643383279502884;


signed main(){
    io;
    tc{
        int n; cin>>n;
        vi x(n);
        forl(n)cin>>x[i];
        ll r1=0, r2=0;
        forl(n-1){r1+=abs(x[i]-x[i+1]);}
        r2=r1;
        r2*=2;
        vi y=x;
        sort(y.begin(), y.end());
        int a=y[n/2];
        forl(n)r1+=abs(x[i]-a);
        if (r1<r2){
            forl(n)cout<<a<<' ';
        }else{
            forl(n)cout<<x[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}

/*CLIPBOARD*/
/*


*/