#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define YESNO(x) cout << (x) ? "YES" : "NO" << endl;
using namespace std;

using ld = long double;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define fi first
#define se second

map<pii, pll> memo;

pll add(pll a, pll b) { //helper to add two fractions a and b and return the result in its most reduced form
    ll num = a.fi*b.se+b.fi*a.se;
    ll den = a.se*b.se;
    ll div = gcd(num, den);
    return {num/div, den/div};
}

pll dfs(int row, int col, int nrow, int ncol, vector<string>& grid) {
    if (row<0||row>=nrow||col<0||col>=ncol) return {0, 0}; //out of bounds, no more paths so 0;

    if (grid[row][col]=='.'||grid[row][col]=='X') return {0, 1}; //return 1 path if we hit an open cell or the target; 0 paths if we hit an open cell but we still have 1 way to get there so its 0/1; 0
    
    pii st = {row, col}; //make a state to push/check with memo (and it stores the current cell at which we are at)
    if (memo.count(st)) return memo[st];
    
    char c = grid[row][col];  //current cell in the grid
    const int drow[] = {-1, 1, 0, 0}; //directional vectors for {n,s,e,w}
    const int dcol[] = {0, 0, -1, 1};
    const char oppo[] = {'v', '^', '>', '<'}; //opposite directions of arrows

    if (c=='^'||c=='v'||c=='<'||c=='>') {
        int diridx = (c=='^')?0:(c=='v')?1:(c=='<')?2:3; //get the direction index for curr cell
        int nxtrow = row+drow[diridx];
        int nxtcol = col+dcol[diridx];

        if (nxtrow<0||nxtrow>=nrow||nxtcol<0||nxtcol>=ncol) return memo[st] = {1LL, 1LL};
        return memo[st] = dfs(nxtrow, nxtcol, nrow, ncol, grid);
    }
    
    vector<pll> res;
    for (int di=0; di<4; di++) { //test on all the 4 directions since from a + cell we can go in any direction
        int nxtrow = row+drow[di]; int nxtcol = col+dcol[di];
        if (nxtrow<0||nxtrow>=nrow||nxtcol<0||nxtcol>=ncol) continue;
        char nxtc = grid[nxtrow][nxtcol]; //keep our next cell so we can check if its a wall target or arrow
        if (nxtc=='X') {res.pb({0, 1});} //if we hit the target then we have 1 path and 1 way to get there, so add 1;
        else if (nxtc=='^'||nxtc=='v'||nxtc=='<'||nxtc=='>') {if (nxtc!=oppo[di]) res.pb(dfs(nxtrow, nxtcol, nrow, ncol, grid));} //if we hit an arrow in any dir, we can only continue if it continues keep going until it doesnt
    }
    int pthc = res.size();
    if (pthc==0) return memo[st] = {0, 1}; //if we dont have any paths, return 0 paths and 1 way to get there {0/1};

    pll tt = {0, 1};
    for (auto& p:res) tt = add(tt, p); //sum paths from all 4 directions
    tt.se*=pthc; //we do tt.se*=pthc to create a common denominator for all paths so we can easily add them together below
    ll div = gcd(tt.fi, tt.se); //reduce the frac
    return memo[st] = {tt.fi/div, tt.se/div}; //store in memo and return res
}

pll solve(int numRows, int numCols, vector<string>& grid) {
    memo.clear();
    return dfs(0, 0, numRows, numCols, grid);
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
