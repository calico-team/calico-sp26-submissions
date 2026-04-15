#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

bool bad(char c){
    return c=='x'||c=='X';
}

bool conv(char c){
    return c=='<'||c=='>'||c=='^'||c=='v';
}

pair<int,int> dir(char c){
    if(c=='^')return {-1,0};
    if(c=='v')return {1,0};
    if(c=='<')return {0,-1};
    return {0,1};
}

bool points_back(char c,int r,int col,int sr,int sc){
    auto [dr,dc]=dir(c);
    return r+dr==sr&&col+dc==sc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        vector<vector<int>> id(N, vector<int>(M, -1));
        vector<pair<int,int>> pos;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(a[i][j]!='.'){
                    id[i][j]=pos.size();
                    pos.push_back({i,j});
                }
            }
        }

        int V=pos.size();
        vector<vector<int>> g(V);
        vector<int> indeg(V,0),deg(V,0);
        long long den=1;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        for(int u=0;u<V;u++){
            auto [r,c]=pos[u];
            char t=a[r][c];

            if(bad(t))continue;

            if(conv(t)){
                auto [x,y]=dir(t);
                int nr=r+x,nc=c+y;
                if(0<=nr&&nr<N&&0<=nc&&nc<M){
                    int v=id[nr][nc];
                    g[u].push_back(v);
                    indeg[v]++;
                }
                continue;
            }

            for(int k=0;k<4;k++){
                int nr=r+dr[k],nc=c+dc[k];
                if(nr<0||nr>=N||nc<0||nc>=M)continue;
                char nt=a[nr][nc];
                if(bad(nt)||(conv(nt)&&!points_back(nt,nr,nc,r,c))){
                    int v=id[nr][nc];
                    g[u].push_back(v);
                    indeg[v]++;
                }
            }

            deg[u]=g[u].size();
            den*=deg[u];
        }

        vector<long long> ways(V,0);
        queue<int> q;
        for(int i=0;i<V;i++)if(indeg[i]==0)q.push(i);
        ways[id[0][0]]=den;

        long long num=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();

            auto [r,c]=pos[u];
            char t=a[r][c];
            long long cur=ways[u];

            if(bad(t))continue;

            if(conv(t)){
                if(g[u].empty()){
                    num+=cur;
                }else{
                    int v=g[u][0];
                    ways[v]+=cur;
                    if(--indeg[v]==0)q.push(v);
                }
                continue;
            }

            long long each=cur/deg[u];
            for(int v:g[u]){
                ways[v]+=each;
                if(--indeg[v]==0)q.push(v);
            }
        }

        if(num==0){
            cout << "0 1\n";
            continue;
        }
        long long g2=gcd(num,den);
        cout << num/g2 << ' ' << den/g2 << '\n';
    }

    return 0;
}
