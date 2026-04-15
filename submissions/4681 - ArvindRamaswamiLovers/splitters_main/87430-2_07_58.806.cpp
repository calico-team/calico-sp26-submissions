#include <bits/stdc++.h>
using namespace std;
using ll =long long;
struct Rational {
    ll num,den;
};
ll gcdll(ll a,ll b) {
    return b ? gcdll(b, a% b) : a;
}
Rational normalizeFrac(Rational a) {
    if(a.num ==0) return{0,1};
    ll g =gcdll(abs(a.num), a.den);
    a.num/=g;
    a.den /=g;
    return a;
}
Rational addFrac(Rational a, Rational b) {
    ll p= a.num* b.den +b.num* a.den;
    ll q =a.den *b.den;
    return normalizeFrac({p,q});
}
Rational mulFrac(Rational a, Rational b) {
    return normalizeFrac({a.num* b.num,a.den* b.den});
}
Rational divideFrac(Rational a,ll x){
    return normalizeFrac({a.num, a.den *x});
}
int N, M;
vector<string> g;
bool inside(int r,int c) {
    return r >=0&& r <N && c>=0 && c <M;
}
pair<int,int> dir(char c) {
    if (c == '>')return {0,1};
    if (c =='<') return {0, -1};
    if (c== '^') return {-1, 0};
    if(c=='v') return {1 ,0};
    return {0,0};
}
bool goesBack(int r,int c, int nr,int nc){
    auto [dr, dc] = dir(g[nr][nc]);
    return(nr+ dr == r &&nc +dc== c);
}
Rational solve(int r,int c) {
    char t= g[r][c];
    if (t =='X') return {0,1};
    if(t!= 'S') {
        auto [dr,dc] =dir(t);
        int nr = r+dr, nc= c +dc;
        if (!inside(nr,nc)) {
            return {1 ,1}; 
        }
        return solve(nr,nc);
    }
    vector<pair<int,int>> nxt;
    int drs[4] ={0, 0 ,1,-1};
    int dcs[4]= {1,-1,0,0};
    for(int i =0;i <4; i++) {
        int nr =r + drs[i];
        int nc= c + dcs[i];
        if(!inside(nr,nc)) continue;
        if (g[nr][nc]=='X') {
            nxt.push_back({nr,nc});
        }else if (g[nr][nc] !='.' && g[nr][nc]!='S') {
            if (!goesBack(r,c,nr,nc)) {
                nxt.push_back({nr,nc});
            }
        }
    }
    Rational res ={0,1};
    int k= nxt.size();
    for(auto [nr,nc]: nxt) {
        Rational sub = solve(nr,nc);
        res = addFrac(res, divideFrac(sub, k));
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x; cin>>x;
    while(x--) {
        cin >>N >> M;
        g.resize(N);
        for (int i= 0;i< N; i++) cin >>g[i];
        Rational ans= solve(0,0);
        ans = normalizeFrac(ans);
        cout << ans.num<<" " << ans.den <<"\n";
    }
}