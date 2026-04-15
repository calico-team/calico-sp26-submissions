// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

long long N, M;
long long id(long long i, long long j) {return (i-1)*M+j;}

pair<long long, long long> af(pair<long long, long long> p, pair<long long, long long> q) {long long g = gcd(p.first*q.second+q.first*p.second,q.second*p.second); return {(p.first*q.second+q.first*p.second)/g,p.second*q.second/g};}

void solve() {
    cin >> N >> M;
    vector<vector<long long>> adj(N*M+1);
    vector<long long> tp(N*M+1); //0=spl edges,1=passout,2 = destr
    vector<vector<char>> A(N+1,vector<char>(M+1));
    for (long long i = 1; i <= N; i++) {
        string s; cin >> s;
        for (long long j = 1; j <= M; j++) {
            A[i][j]=s[j-1];
        }
    }
    for (long long i = 1; i <= N; i++) {
        for (long long j = 1; j <= M; j++) {
            if (A[i][j]=='v') {if (i==N) {tp[id(i,j)]=1;} else {adj[id(i,j)].push_back(id(i+1,j));}}
            else if (A[i][j]=='>') {if (j==M) {tp[id(i,j)]=1;} else {adj[id(i,j)].push_back(id(i,j+1));}}
            else if (A[i][j]=='^') {if (i==1) {tp[id(i,j)]=1;} else {adj[id(i,j)].push_back(id(i-1,j));}}
            else if (A[i][j]=='<') {if (j==1) {tp[id(i,j)]=1;} else {adj[id(i,j)].push_back(id(i,j-1));}}
            else if (A[i][j]=='X') {tp[id(i,j)]=2;}
            else if (A[i][j]=='S') {
                if (A[i+1][j]=='^'||A[i+1][j]=='.') {}
                else {adj[(id(i,j))].push_back(id(i+1,j));}
                if (A[i-1][j]=='v'||A[i-1][j]=='.') {}
                else {adj[(id(i,j))].push_back(id(i-1,j));}
                if (A[i][j-1]=='>'||A[i][j-1]=='.') {}
                else {adj[(id(i,j))].push_back(id(i,j-1));}
                if (A[i][j+1]=='<'||A[i][j+1]=='.') {}
                else {adj[(id(i,j))].push_back(id(i,j+1));}
            }
        }
    }
    vector<pair<long long, long long>> dp(N*M+1);
    for (long long i = 1; i <= N*M; i++) {if (tp[i]==1) {dp[i]={1,1};} else {dp[i]={0,1};}}
    vector<long long> indeg(N*M+1);
    for (long long i = 1; i <= N*M; i++) {for (auto x : adj[i]) {indeg[x]++;}}
    queue<long long> q;
    for (long long i = 1; i <= N*M; i++) {if (!indeg[i]) {q.push(i);}}
    vector<long long> topo;
    while (!q.empty()) {
        long long n = q.front(); q.pop();
        topo.push_back(n);
        for (auto x : adj[n]) {if (!(--indeg[x])) {q.push(x);}}
    }
    reverse(topo.begin(),topo.end());
    for (auto x : topo) {
        if (adj[x].empty()) {continue;}
        for (auto y : adj[x]) {dp[x]=af(dp[x],dp[y]);}
        dp[x].second*=(adj[x].size());
        long long g = gcd(dp[x].first,dp[x].second);
        dp[x].first/=g;
        dp[x].second/=g;
    }
    cout << dp[1].first << " " << (dp[1].first==0?1:dp[1].second) << endl;
}

int main() {
	long long T; cin >> T;
    while (T--) {solve();}
}
