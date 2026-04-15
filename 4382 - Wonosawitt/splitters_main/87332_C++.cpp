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

void solve() {
    int n,m; cin >> n >> m;
    
    vector<str> s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    auto hash = [&](const pii &pos) -> int {return pos.ft * m + pos.sc;}; 
    
    vector<int> indeg(n*m+1);
    vector<vector<int>> adj(n*m+1);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            int cur = hash({i, j});

            if(s[i][j] == 'v') {
                if(i==n-1) adj[cur].Pb(hash({n, 0}));
                else adj[cur].Pb(hash({i+1, j}));
            } 

            else if(s[i][j] == '^') {
                if(i==0) adj[cur].Pb(hash({n, 0}));
                else adj[cur].Pb(hash({i-1, j}));
            } 

            else if(s[i][j] == '>') {
                if(j==m-1) adj[cur].Pb(hash({n, 0}));
                else adj[cur].Pb(hash({i, j+1}));
            } 

            else if(s[i][j] == '<'){
                if(j==0) adj[cur].Pb(hash({n, 0}));
                else adj[cur].Pb(hash({i, j-1}));
            } 

            else if(s[i][j] == 'S') {
                if(0<=i-1 && (s[i-1][j]!='v' && s[i-1][j]!='.')) adj[cur].Pb(hash({i-1, j}));
                if(i+1<n && (s[i+1][j]!='^' && s[i+1][j]!='.')) adj[cur].Pb(hash({i+1, j}));
                if(0<=j-1 && (s[i][j-1]!='>' && s[i][j-1]!='.')) adj[cur].Pb(hash({i, j-1}));
                if(j+1<m && (s[i][j+1]!='<' && s[i][j+1]!='.')) adj[cur].Pb(hash({i, j+1}));
            }
        }
    
    n = n*m+1;
    for(int i=0;i<n;i++)
        for(auto &j:adj[i]) indeg[j]++;

    queue<int> q; q.push(0);
    vector<int> a(n), b(n, 1);
    a[0] = b[0] = 1;

    auto join = [&](const int &x1, const int &y1, const int &x2, const int &y2) -> pii {
        int atas = x1*y2 + x2*y1;
        int bawah = y1*y2;

        int fpb = __gcd(atas, bawah);
        atas /= fpb, bawah /= fpb;
        return {atas, bawah};
    };

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        int div = adj[cur].size();
        int nxta = a[cur], nxtb = b[cur] * div;
        
        // cout << cur << " : ";
        for(auto &next:adj[cur]) {
            // cout << next << " ";
            pii res = join(a[next], b[next], nxta, nxtb);
            a[next] = res.ft, b[next] = res.sc;

            indeg[next]--;
            if(indeg[next] == 0) q.push(next);
        }
        // cout << nl;
    }
    cout << a[n-1] << " " << b[n-1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0); 
    // FREOPEN("");
    
    int T = 1; cin >> T;
    while(T--) solve();
}
