// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int N, M, K;

bool ch(int d, vector<vector<int>> &pp, int &x, int &y) {
    for (int i = d; i <= N+M; i++) {
        for (int j = d; j <= N+M; j++) {
            if (pp[i][j]-pp[i-d][j]-pp[i][j-d]+pp[i-d][j-d]>=K) {x=i; y=j; return true;}
        }
    }
    return false;
}

void solve() {
    cin >> N >> M >> K;
    vector<vector<int>> A(N+1,vector<int>(M+1,0));
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        for (int j = 1; j <= M; j++) {
            if (s[j-1]=='-') {A[i][j]=1;}
        }
    }
    vector<vector<int>> gr(N+M+1,vector<int>(N+M+1,0));
    vector<vector<bool>> av(N+M+1,vector<bool>(N+M+1,false));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            gr[i+j][i-j+M]=A[i][j];
            if (A[i][j]) {av[i+j][i-j+M]=true;}
        }
    }
    vector<vector<int>> pp(N+M+1,vector<int>(N+M+1,0));
    for (int i = 1; i <= N+M; i++) {
        for (int j = 1; j <= N+M; j++) {
            pp[i][j]=pp[i][j-1]+pp[i-1][j]-pp[i-1][j-1]+gr[i][j];
        }
    }
    int x;
    int y;
    int lo = 1;
    int hi = N+M;
    while (lo<hi) {
        int mid = (lo+hi)/2;
        if (ch(mid,pp,x,y)) {hi=mid;}
        else {lo=mid+1;}
    }
    ch(lo,pp,x,y);
    vector<pair<int, int>> aa;
    for (int i = x-lo+1; i <= x; i++) {
        for (int j = y-lo+1; j <= y; j++) {
            if (av[i][j]&&aa.size()<K) {
                int ii = (i+j-M)/2;
                int jj = i-ii;
                aa.push_back({ii,jj});
            }
        }
    }
    for (auto x : aa) {cout << x.first-1 << " " << x.second-1 << endl;}
}

int main() {
	int T; cin >> T;
    while (T--) {solve();}
}
