#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

struct Frac {
    i128 num, den;

    Frac(i128 n=0, i128 d=1) {
        if (d < 0) n = -n, d = -d;
        i128 g = std::gcd((i128)llabs((long long)n), (i128)llabs((long long)d));
        num = n / g;
        den = d / g;
    }

    Frac operator+(const Frac &o) const {
        return Frac(num * o.den + o.num * den, den * o.den);
    }

    Frac operator-(const Frac &o) const {
        return Frac(num * o.den - o.num * den, den * o.den);
    }

    Frac operator*(const Frac &o) const {
        return Frac(num * o.num, den * o.den);
    }

    bool isZero() const { return num == 0; }
};

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int dir(char c){
    if(c=='^') return 0;
    if(c=='>') return 1;
    if(c=='v') return 2;
    return 3;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int N,M; cin >> N >> M;
        vector<string> g(N);
        for(auto &r: g) cin >> r;

        auto inside = [&](int r,int c){
            return r>=0 && r<N && c>=0 && c<M;
        };

        vector<int> id(N*M, -1);
        vector<pair<int,int>> nodes;

        int COLLECT = N*M;
        int DESTROY = N*M+1;

        auto getId = [&](int r,int c){
            return r*M + c;
        };

        int V = N*M + 2;

        vector<vector<pair<int,Frac>>> out(V);

        auto add_edge = [&](int u,int v,Frac p){
            out[u].push_back({v,p});
        };

        for(int r=0;r<N;r++){
            for(int c=0;c<M;c++){
                char ch = g[r][c];
                if(ch=='.') continue;

                int u = getId(r,c);

                if(ch=='X'){
                    add_edge(u, DESTROY, Frac(1,1));
                    continue;
                }

                if(ch=='^'||ch=='v'||ch=='<'||ch=='>'){
                    int d = dir(ch);
                    int nr=r+dr[d], nc=c+dc[d];
                    int v = (!inside(nr,nc)) ? COLLECT : getId(nr,nc);
                    add_edge(u,v,Frac(1,1));
                    continue;
                }

                if(ch=='S'){
                    vector<int> nxt;

                    for(int k=0;k<4;k++){
                        int nr=r+dr[k], nc=c+dc[k];
                        if(!inside(nr,nc)) continue;
                        if(g[nr][nc]=='.') continue;

                        char nb=g[nr][nc];

                        if(nb=='X'){
                            nxt.push_back(getId(nr,nc));
                        } else {
                            int d=dir(nb);
                            int br=nr+dr[d], bc=nc+dc[d];
                            if(!(br==r && bc==c)){
                                nxt.push_back(getId(nr,nc));
                            }
                        }
                    }

                    int deg = nxt.size();
                    for(int v: nxt){
                        add_edge(u,v,Frac(1,deg));
                    }
                }
            }
        }

        vector<int> idx(V,-1);
        vector<int> vars;

        for(int i=0;i<V;i++){
            if(i!=COLLECT && i!=DESTROY) {
                idx[i]=vars.size();
                vars.push_back(i);
            }
        }

        int n = vars.size();

        vector<vector<Frac>> A(n, vector<Frac>(n+1, Frac(0,1)));

        auto add_eq = [&](int i){
            int u = vars[i];
            A[i][i] = Frac(1,1);

            for(auto [v,p]: out[u]){
                if(v==COLLECT || v==DESTROY) continue;
                A[i][idx[v]] = A[i][idx[v]] - p;
            }
        };

        for(int i=0;i<n;i++) add_eq(i);

        // start = (0,0)
        int start = getId(0,0);
        if(start!=COLLECT && start!=DESTROY){
            A[idx[start]][n] = Frac(1,1);
        }

        // Gaussian elimination
        for(int i=0;i<n;i++){
            int piv=i;
            for(int j=i;j<n;j++){
                if(!A[j][i].isZero()){ piv=j; break; }
            }
            swap(A[i],A[piv]);

            Frac div = A[i][i];
            for(int j=i;j<=n;j++){
                A[i][j] = Frac(A[i][j].num * div.den, A[i][j].den * div.num);
            }

            for(int j=0;j<n;j++){
                if(j==i) continue;
                if(A[j][i].isZero()) continue;

                Frac f = A[j][i];
                for(int k=i;k<=n;k++){
                    A[j][k] = A[j][k] - f * A[i][k];
                }
            }
        }

        Frac ans = Frac(0,1);
        for(auto [v,p]: out[start]){
            if(v==COLLECT){
                ans = ans + p;
            } else if(v!=DESTROY){
                ans = ans + p * A[idx[v]][n];
            }
        }

        if(ans.num==0){
            cout<<"0 1\n";
        } else {
            i128 g = std::gcd((i128)llabs((long long)ans.num),
                              (i128)llabs((long long)ans.den));
            cout << (long long)(ans.num/g) << " "
                 << (long long)(ans.den/g) << "\n";
        }
    }
}