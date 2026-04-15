#include <bits/stdc++.h>
#include <numeric> 

using namespace std;

//~ template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
//~ template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
//~ void dbg_out() { cerr << endl; }
//~ template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
//~ #ifdef LOCAL
//~ #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//~ #else
//~ #define dbg(...)
//~ #endif

#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll gcd(ll a, ll b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

ll ceil_division(ll a, ll b) {
	return (a + b - 1) / b;
}

ll lcm(int a, int b) {
    return a * b / gcd(a, b);
}

//~ const int MAX_N = 1e5 + 5;
//~ const ll MOD = 1e9 + 7;
//~ const ll INF = 1e9;
//~ const ld EPS = 1e-9;

void solve() {	
	string a,b;
	cin>>a>>b;
	
	int p1 = 0;
	int p2 = 0;
	
	while(p1 < a.length() && p2 < b.length()){
		if(a[p1] == b[p2]){
			p1++;
			p2++;
		}
		else {
			a[p1] = '#';
			p1++;
		}
	}
	for(int i = p1; i<a.length(); i++) a[i] = '#';
	cout<<a<<"\n";
}

int main() {	
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
