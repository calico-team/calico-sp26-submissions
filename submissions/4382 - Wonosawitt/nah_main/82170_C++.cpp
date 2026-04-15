#include<bits/stdc++.h>
using namespace std;

void FREOPEN(const string &prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

#define debug(c) cout << #c << " = " << c << endl
#define debugc() cout << "PASS" << endl

#define nl "\n"
#define fl flush
#define int long long

#define ll long long
#define str string
#define ld long double

#define Pb push_back
#define pB pop_back
#define ub upper_bound
#define lb lower_bound
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define ft first
#define sc second

const ll mod = 1e9+7;
const ld pi = 3.1415926535;

void solve() {
    int n,p,r,k; cin >> n >> p >> r >> k;
    
    bool flag = 0;
    for(int i=1;i<=n;i++) {
        int e; cin >> e;
        p -= e;

        if(p<0) flag = 1;
        
        p += r * (i%k==0);
    }
    cout << (flag ? "nah i'd lose" : "nah i'd win") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0); 
    // FREOPEN("");
    
    int T = 1; cin >> T;
    while(T--) solve();
}