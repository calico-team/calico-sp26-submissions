#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<pair<int,int>>;
template <class T> using PQ = priority_queue<T>; 
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const char nl = '\n';
constexpr array<pair<int,int>,8> dir = {{
    {1,0}, {0,1}, {0,-1}, {-1,0},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
}};
const int MOD = 998244353;

template<class T> inline bool chkmax(T &a, const T &b){ 
    if(b > a){ a = b; return true; } 
    return false; 
}

template<class T> inline bool chkmin(T &a, const T &b){ 
    if(b < a){ a = b; return true; } 
    return false; 
}

const int N = 1010;

int n,m,k,p,q;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) { x = 1; y = 0; return a; }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int get(int v_x, int v_y, int X, int Y, int n, int m) {
    X = (X % n + n) % n;
    Y = (Y % m + m) % m;
    int s1, t1, s2, t2;
    
    int g1 = exgcd(v_x, n, s1, t1);
    if (X % g1 != 0) return -1;
    int M1 = n / g1;
    int r1 = (s1 % M1 + M1) % M1;
    r1 = r1 * (X / g1 % M1) % M1;

    int g2 = exgcd(v_y, m, s2, t2);
    if (Y % g2 != 0) return -1;
    int M2 = m / g2;
    int r2 = (s2 % M2 + M2) % M2;
    r2 = r2 * (Y / g2 % M2) % M2;

    int k, l;
    int D = (r2 - r1 % M2 + M2) % M2;
    int g = exgcd(M1, M2, k, l);
    if (D % g != 0) return -1;

    int mod = M2 / g;
    k = (k % mod + mod) % mod;
    k = k * (D / g % mod) % mod;

    int ans = k * M1 + r1;
    int L = M1 * (M2 / g);
    ans = (ans % L + L) % L;
    if (ans == 0) ans = L;
    return ans;
}

void SOLVE(int Case){
    cin>>k>>n>>m>>p>>q;
    VPI a(k);
    rep(i,0,k-1) {
        cin>>a[i].F>>a[i].S;
    }
    int x0=a[0].F, y0=a[0].S;
    int ans=LLINF, aans=-1; 
    rep(i, 0, k - 1){
        int s=get(q,p,a[i].F-x0,a[i].S-y0,n,m);
        if(s!=-1 && s<ans){
            ans=s;
            aans=i;
        }
    }
    cout<<aans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int T=1;
	cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}