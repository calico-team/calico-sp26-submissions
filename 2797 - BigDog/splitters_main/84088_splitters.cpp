#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

bool is_destroy(char c){
    return c=='x'||c=='X';
}

bool is_splitter(char c){
    return c=='s'||c=='S';
}

bool is_conv(char c){
    return c=='<'||c=='>'||c=='^'||c=='v';
}

pair<int,int> go(char c){
    if(c=='^')return {-1,0};
    if(c=='v')return {1,0};
    if(c=='<')return {0,-1};
    return {0,1};
}

bool back(char c,int r,int col,int sr,int sc){
    auto [dr,dc]=go(c);
    return r+dr==sr&&col+dc==sc;
}

/**
 * Simulate the factory and return the final output as the fraction P / Q.
 *
 * N: number of rows in the factory grid
 * M: number of columns in the factory grid
 * factory: vector of N strings of length M, each character one of '^<>vSX.'
 */
pair<long long, long long> solve(int N, int M, vector<string>& factory) {
    vector<vector<int>> id(N,vector<int>(M,-1));
    vector<pair<int,int>> pos;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(factory[i][j]!='.'){
                id[i][j]=pos.size();
                pos.push_back({i,j});
            }
        }
    }

    int V=pos.size();
    vector<vector<int>> g(V);
    vector<int> deg(V,0),out(V,0);

    long long den=1;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    for(int u=0;u<V;u++){
        auto [r,c]=pos[u];
        char t=factory[r][c];

        if(is_destroy(t))continue;

        if(is_conv(t)){
            auto [x,y]=go(t);
            int nr=r+x,nc=c+y;
            if(0<=nr&&nr<N&&0<=nc&&nc<M){
                int v=id[nr][nc];
                g[u].push_back(v);
                deg[v]++;
            }
            continue;
        }

        if(is_splitter(t)){
            for(int k=0;k<4;k++){
                int nr=r+dr[k],nc=c+dc[k];
                if(!(0<=nr&&nr<N&&0<=nc&&nc<M))continue;

                char nt=factory[nr][nc];
                bool ok=false;

                if(is_destroy(nt))ok=true;
                else if(is_conv(nt)&&!back(nt,nr,nc,r,c))ok=true;

                if(ok){
                    int v=id[nr][nc];
                    g[u].push_back(v);
                    deg[v]++;
                }
            }
            out[u]=g[u].size();
            den*=out[u];
        }
    }

    vector<long long> mass(V,0);
    queue<int> q;
    for(int i=0;i<V;i++)if(deg[i]==0)q.push(i);

    mass[id[0][0]]=den;
    long long got=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        auto [r,c]=pos[u];
        char t=factory[r][c];
        long long cur=mass[u];

        if(is_destroy(t))continue;

        if(is_conv(t)){
            if(g[u].empty()){
                got+=cur;
                continue;
            }
            int v=g[u][0];
            mass[v]+=cur;
            deg[v]--;
            if(deg[v]==0)q.push(v);
            continue;
        }

        long long each=cur/out[u];
        for(int v:g[u]){
            mass[v]+=each;
            deg[v]--;
            if(deg[v]==0)q.push(v);
        }
    }

    if(got==0)return {0,1};
    long long gg=gcd(got,den);
    return {got/gg,den/gg};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> factory(N);
        for (int i = 0; i < N; i++) cin >> factory[i];
        auto [P, Q] = solve(N, M, factory);
        cout << P << " " << Q << "\n";
    }
    return 0;
}
