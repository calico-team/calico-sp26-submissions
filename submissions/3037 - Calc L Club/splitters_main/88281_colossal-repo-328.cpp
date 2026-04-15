#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> a;
vector<vector<bool>> visited;
vector<vector<pair<long long,long long>>> dp;

void add(pair<long long,long long>& c, pair<long long,long long> d) {
    c = {c.first*d.second+d.first*c.second,c.second*d.second};

}

bool v(char c) {
    return c == 'X' || c == '>' || c == '<' || c == '^' || c == 'v';
}

pair<long long,long long> dfs(int x, int y) {
    if (visited[x][y]) return dp[x][y];
    if (a[x][y] == '>') {
        if (y == m-1) dp[x][y] = {1,1};
        else dp[x][y] = dfs(x,y+1);
    } else if (a[x][y] == 'v') {
        if (x == n-1) dp[x][y] = {1,1};
        else dp[x][y] = dfs(x+1,y);
    } else if (a[x][y] == '<') {
        if (y) dp[x][y] = dfs(x,y-1);
        else dp[x][y] = {1,1};
    } else if (a[x][y] == '^') {
        if (x) dp[x][y] = dfs(x-1,y);
        else dp[x][y] = {1,1};
    } else if (a[x][y] == 'X') dp[x][y] = {0,1};
    else {
        int s = 0;
        dp[x][y] = {0,1};
        if (x && v(a[x-1][y]) && a[x-1][y] != 'v') {
            add(dp[x][y],dfs(x-1,y));
            ++s;
        }
        if (y && v(a[x][y-1]) && a[x][y-1] != '>') {
            add(dp[x][y],dfs(x,y-1));
            ++s;
        }
        if (x < n-1 && v(a[x+1][y]) && a[x+1][y] != '^') {
            add(dp[x][y],dfs(x+1,y));
            ++s;
        }
        if (y < m-1 && v(a[x][y+1]) && a[x][y+1] != '<') {
            add(dp[x][y],dfs(x,y+1));
            ++s;
        }
        if (dp[x][y].first%s) {
            if (s == 4 && dp[x][y].first%2 == 0) {
                dp[x][y].first /= 2;
                dp[x][y].second *= 2;
            } else dp[x][y].second *= s;
        } else dp[x][y].first /= s;
    }
    visited[x][y] = true;
    return dp[x][y];
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        a.resize(n);
        visited.assign(n,vector<bool>(m));
        dp.assign(n,vector<pair<long long,long long>>(m));
        for (string& i : a) cin >> i;
        auto [g,f] = dfs(0,0);
        if (g) {
            long long h = gcd(g,f);
            cout << g/h << ' ' << f/h << endl;
        } else cout << "0 1\n";
    }    
}