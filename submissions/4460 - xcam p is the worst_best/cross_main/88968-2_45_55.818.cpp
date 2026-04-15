#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define FOR(i, a, b) for(int i=(a),_b=(b),_s=((a)<=_b?1:-1);i!=_b+_s;i+=_s)


inline void fast_io(string name="") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(sz(name)) {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

const int N=1e3+7;
int ass[N][N]={};
vector<pair<int,int>> adj[N][N]={};
int n,m;
bool badn(int x) {
    if(x<0 || x>=n) return true;
    return false;
}
bool badm(int y) {
    if(y<0 || y>=m) return true;
    return false;
}
bool valid(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x5,int y5) {
    if(badn(x1)|| badm(y1) || badn(x2) || badm(y2) || badn(x3) || badm(y3) || badn(x4) || badm(y4) || badn(x5) || badm(y5)) return false;
    return true;
}
void dfs(int x,int y,int assed) {
    stack<tuple<int,int,int>> st;
    st.push({x,y,assed});
    while(!st.empty()) {
        auto [cx,cy,assed] = st.top(); st.pop();
        
        for(auto [nx,ny]:adj[cx][cy]) {
            if(ass[nx][ny]==-1) {
                set<int> avail;
                FOR(i,0,4) avail.insert(i);
        
                for(auto [nnx,nny]:adj[nx][ny]) {
                    if(ass[nnx][nny]!=-1) avail.erase(ass[nnx][nny]);
                }
                
                avail.erase(ass[cx][cy]);
        
                if(!avail.empty()) {
                    ass[nx][ny]=*avail.begin();
                    st.push({nx,ny,ass[nx][ny]});
                }
            }
        }

    }
}
void solve() {
    cin>>n>>m;
    memset(ass,-1,sizeof ass);
    FOR(i,0,n-1) FOR(j,0,m-1) adj[i][j].clear();
    FOR(i,0,n-1) FOR(j,0,m-1) {
        // center
        if(valid(i,j,i+1,j,i-1,j,i,j+1,i,j-1)) {
            adj[i][j].push_back({i+1,j}),adj[i][j].push_back({i-1,j});
            adj[i][j].push_back({i,j+1}), adj[i][j].push_back({i,j-1});
        }
        // top
        if(valid(i,j,i-1,j,i-1,j+1,i-1,j-1,i-2,j)) {
            
            adj[i][j].push_back({i-1,j+1}), adj[i][j].push_back({i-1,j-1});
            adj[i][j].push_back({i-2,j}), adj[i][j].push_back({i-1,j});
        }
        // left
        if(valid(i,j,i,j-1,i+1,j-1,i-1,j-1,i,j-2)) {
            
            adj[i][j].push_back({i+1,j-1}), adj[i][j].push_back({i-1,j-1});
            adj[i][j].push_back({i,j-2}), adj[i][j].push_back({i,j-1});
        }
        // right
        if(valid(i,j,i,j+1,i+1,j+1,i-1,j+1,i,j+2)) {
            
            adj[i][j].push_back({i+1,j+1}), adj[i][j].push_back({i-1,j+1});
            adj[i][j].push_back({i,j+2}), adj[i][j].push_back({i,j+1});
        }
        // bottom
        if(valid(i,j,i+1,j,i+1,j+1,i+1,j-1,i+2,j)) {
            
            adj[i][j].push_back({i+1,j+1}), adj[i][j].push_back({i+1,j-1});
            adj[i][j].push_back({i+2,j}), adj[i][j].push_back({i+1,j});
        }
    }
    FOR(i,0,n-1) FOR(j,0,m-1) {
        if(ass[i][j]==-1) {
            ass[i][j]=0;
            dfs(i,j,0);
        }
    }
    FOR(i,0,n-1) {
        FOR(j,0,m-1) {
            cout<<ass[i][j]<<" ";
        }
        cout<<'\n';
    }
}

signed main() {
    fast_io(); 

    int tc;
    cin>>tc;

    while(tc--) {
        solve();
    }
    return 0;
}