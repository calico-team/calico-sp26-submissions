#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

int numR, numC;
vector<string> grid;
vector<vector<pll>> dp;

ll gcdll(ll a, ll b) {
    if (a < 0) a=-a;
    if (b < 0) b=-b;
    while (b) {
        ll t = a%b;
        a=b;
        b=t;
    }
    return a;
}

bool isValid(int r, int c) {
    return 0 <= r && r < numR && 0 <= c && c < numC;
}

pll simp(pll f) {
    if (f.first == 0) return {0, 1};
    ll g = gcdll(f.first, f.second);
    return {f.first/g, f.second/g};
}

pll add(pll a, pll b) {
    ll g = gcdll(a.second, b.second);
    ll l = a.second/g;
    return simp({a.first*(b.second/g)+b.first*l, l*b.second});
}

pll divide(pll a, ll d) {
    ll g = gcdll(a.first, d);
    a.first/=g;
    d/=g;
    return simp({a.first, a.second*d});
}

bool isConv(char ch) {
    return ch == '<' || ch == '>' || ch == '^' || ch == 'v';
}

pll dfs(int r, int c) {
    if (dp[r][c].first != -1) return dp[r][c];

    char ch = grid[r][c];
    if (ch == 'X') return dp[r][c] = {0, 1};

    if (isConv(ch)) {
        int nr = r, nc = c;
        if (ch == '<') nc--;
        if (ch == '>') nc++;
        if (ch == '^') nr--;
        if (ch == 'v') nr++;

        if (!isValid(nr, nc)){
            return dp[r][c] = {1, 1};
        }
        
        return dp[r][c] = dfs(nr, nc);
    }

    pll ans = {0, 1};
    int deg = 0;

    if (isValid(r-1, c) && (grid[r-1][c] == 'X'|| (isConv(grid[r-1][c]) && grid[r-1][c]!='v'))) {
        ans = add(ans, dfs(r-1, c));
        deg++;
    }
    if (isValid(r+1, c) && (grid[r+1][c] == 'X'|| (isConv(grid[r+1][c]) && grid[r+1][c]!='^'))) {
        ans = add(ans, dfs(r+1, c));
        deg++;
    }
    if (isValid(r, c-1) && (grid[r][c-1] == 'X'|| (isConv(grid[r][c-1]) && grid[r][c-1]!='>'))) {
        ans = add(ans, dfs(r, c-1));
        deg++;
    }
    if (isValid(r, c+1) && (grid[r][c+1] == 'X'|| (isConv(grid[r][c+1]) && grid[r][c+1]!='<'))) {
        ans = add(ans, dfs(r, c+1));
        deg++;
    }

    return dp[r][c] = divide(ans, deg);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >>T;

    while (T--) {
        cin>>numR>>numC;
        grid.assign(numR, "");
        for (string &row: grid) cin >> row;

        dp.assign(numR, vector<pll>(numC, {-1, 1}));

        pll ans = dfs(0, 0);
        cout << ans.first << ' ' << ans.second << '\n';
    }
}
