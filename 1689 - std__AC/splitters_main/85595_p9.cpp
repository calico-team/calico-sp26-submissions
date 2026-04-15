#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using lli=long long int;
using pii=pair<int, int>;
using plli=pair<lli, lli>;
using vlli=vector<lli>;
using vpii=vector<pii>;
using vplli=vector<plli>;
using vvi=vector<vi>;
using vvlli=vector<vlli>;
using vc=vector<char>;
using vvc=vector<vc>;
using vb=vector<bool>;
using vvb=vector<vector<bool>>;

plli add(plli a, plli b){
    lli p=a.first*b.second+a.second*b.first;
    lli q=a.second*b.second;
    lli g=gcd(p, q);
    return {p/g, q/g};
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--){
        int n, m;
        cin >> n >> m;
        vvc A(n, vc(m));
        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j) cin >> A[i][j];
        }
        vvi G(n*m);
        vb col(n*m, false);
        vb rem(n*m, false);
        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                if (A[i][j]=='X'){
                    rem[i*m+j]=true;
                    continue;
                }
                if (A[i][j]=='>'){
                    if (j==m-1) col[i*m+j]=true;
                    else G[i*m+j].push_back(i*m+j+1);
                }else if (A[i][j]=='<'){
                    if (j==0) col[i*m+j]=true;
                    else G[i*m+j].push_back(i*m+j-1);
                }else if (A[i][j]=='^'){
                    if (i==0) col[i*m+j]=true;
                    else G[i*m+j].push_back(i*m+j-m);
                }else if (A[i][j]=='v'){
                    if (i==n-1) col[i*m+j]=true;
                    else G[i*m+j].push_back(i*m+j+m);
                }else if (A[i][j]=='S'){
                    assert(i!=0 && i!=n-1 && j!=0 && j!=m-1);
                    if (A[i][j+1]!='<' && A[i][j+1]!='.') G[i*m+j].push_back(i*m+j+1);
                    if (A[i][j-1]!='>' && A[i][j-1]!='.') G[i*m+j].push_back(i*m+j-1);
                    if (A[i+1][j]!='^' && A[i+1][j]!='.') G[i*m+j].push_back(i*m+j+m);
                    if (A[i-1][j]!='v' && A[i-1][j]!='.') G[i*m+j].push_back(i*m+j-m);
                }
            }
        }
        vi deg(n*m, 0);
        for (int i=0; i<n*m; ++i){
            for (int v : G[i]) ++deg[v];
        }
        queue<int> q;
        vi ord;
        for (int i=0; i<n*m; ++i){
            if (deg[i]==0) q.push(i);
        }
        while (!q.empty()){
            int u=q.front();
            q.pop();
            ord.push_back(u);
            for (int v : G[u]){
                --deg[v];
                if (deg[v]==0) q.push(v);
            }
        }
        reverse(ord.begin(), ord.end());
        vpii dp(n*m);
        for (int u : ord){
            if (col[u]){
                dp[u]={1, 1};
                continue;
            }
            if (rem[u]){
                dp[u]={0, 1};
                continue;
            }
            if (G[u].empty()) continue;
            plli ret={0, 1};
            for (int v : G[u]) ret=add(ret, {dp[v].first, (lli)dp[v].second*G[u].size()});
            dp[u]=ret;
        }
        cout << dp[0].first << ' ' << dp[0].second << endl;
    }
}
/*
2
6 10
v.>>>>v.^.
v.^...v.^.
>>S>S>>>S.
..X.v...v.
....>>>>X.
..........
3 3
vX.
>SX
.X.
*/