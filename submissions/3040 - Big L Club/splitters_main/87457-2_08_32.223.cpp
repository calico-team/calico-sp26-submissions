#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
vector<vector<char>> grid;

vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
vector<vector<vector<pair<int,int>>>> valids;

void reduce(int &a, int &b) {
    while(gcd(a,b) != 1) {
        int gc = gcd(a,b);
        a/=gc;
        b/=gc;
    }
    return;
}

void dfs(int i, int j, int have, int&totalCnt) {
    if(i<0||j<0||i>=n||j>=m) {
        totalCnt += have;
    }
    else if(grid[i][j]=='>') {
        dfs(i,j+1,have,totalCnt);
    }
    else if(grid[i][j]=='v') {
        dfs(i+1,j,have,totalCnt);
    }
    else if(grid[i][j]=='^') {
        dfs(i-1,j,have,totalCnt);
    }
    else if(grid[i][j]=='<') {
        dfs(i,j-1,have,totalCnt);
    }
    else if(grid[i][j]=='X') {
        return;
    }
    else if(grid[i][j]=='.') {
        return;
    }
    else if(grid[i][j]=='S') {
        vector<pair<int,int>> curr = valids[i][j];
        int split = have/curr.size();

        for(auto [ni,nj] : curr) {
            dfs(ni,nj,split,totalCnt);
        }
    }
    else {
        assert(false);
    }
}

void solve() {
    cin >> n >> m;
    grid.assign(n+1,vector<char>(m+1,'-'));
    valids.assign(n+1,vector<vector<pair<int,int>>>(m+1,vector<pair<int,int>>(0)));

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> grid[i][j];

    int total = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j]!='S') continue;

            vector<pair<int,int>> curr;
            for(auto [a,b] : dirs) {
                int ni = i+a, nj = j+b;
                int oriNi = ni, oriNj = nj;

                if(grid[ni][nj]=='.') continue;

                if(grid[ni][nj]=='v') {
                    ni++;
                }
                else if(grid[ni][nj]=='^') {
                    ni--;
                }
                else if(grid[ni][nj]=='<') {
                    nj--;
                }
                else {
                    nj++;
                }

                if(ni!=i||nj!=j) curr.push_back({oriNi,oriNj});
            }
            valids[i][j] = curr;
            total *= curr.size();
        }
    }

    int cnt = 0; // collected
    dfs(0,0,total,cnt);

    if(cnt==0) {
        cout << "0 1" << endl;
        return;
    }
    reduce(cnt,total);
    cout << cnt << " " << total << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        solve();
    }
}