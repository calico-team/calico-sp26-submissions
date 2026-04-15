#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/**
 * Simulate the factory and return the final output as the fraction P / Q.
 *
 * N: number of rows in the factory grid
 * M: number of columns in the factory grid
 * factory: vector of N strings of length M, each character one of '^<>vSX.'
 */
pair<ll, ll> simplify(ll p, ll q) {
    if (p==0) return {0, 1};
    ll g = gcd(p, q);
    return {p/g,q/g};
}

pair<ll, ll> add(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first==0) return b;
    if (b.first==0) return a;

    ll g = gcd(a.second, b.second);
    ll lcm = (a.second/g)*b.second;
    ll num = a.first*(b.second/g)+b.first*(a.second/g);

    return simplify(num, lcm);
}

pair<ll, ll> multiply(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first==0||b.first==0) return {0, 1};

    ll g1 = gcd(a.first, b.second);
    ll g2 = gcd(a.second, b.first);

    ll num = (a.first/g1)*(b.first/g2);
    ll den = (a.second/g2)*(b.second/g1);

    return {num, den};
}

bool isValid(int r, int c, int dir, int N, int M, const vector<string>& factory) {
    if (r<0||r>=N||c<0||c>=M) return false;

    char ch = factory[r][c];
    if (ch=='X') return true;
    if (ch=='^'||ch=='v'||ch=='<'||ch=='>') {
        if (dir==0&&ch=='v') return false;
        if (dir==1&&ch=='^') return false;
        if (dir==2&&ch=='>') return false;
        if (dir==3&&ch=='<') return false;
        return true;
    }

    return false;
}

pair<ll, ll> dfs(int r, int c, int N, int M, const vector<string>& factory, vector<vector<bool>>& visited, vector<vector<pair<ll, ll>>>& memo) {
    int dR[] = {-1, 1, 0, 0};
    int dC[] = {0, 0, -1, 1};

    if (r<0||r>=N||c<0||c>=M) return {1, 1};
    if (visited[r][c]) return memo[r][c];

    visited[r][c] = true;
    char ch = factory[r][c];

    if (ch=='X'||ch=='.') {
        return memo[r][c] = {0, 1};
    } else if (ch=='^') {
        return memo[r][c] = dfs(r-1, c, N, M, factory, visited, memo);
    } else if (ch=='v') {
        return memo[r][c] = dfs(r+1, c, N, M, factory, visited, memo);
    } else if (ch=='<') {
        return memo[r][c] = dfs(r, c-1, N, M, factory, visited, memo);
    } else if (ch=='>') {
        return memo[r][c] = dfs(r, c+1, N, M, factory, visited, memo);
    } else if (ch=='S') {
        pair<ll, ll> sum = {0, 1};
        int cnt =0;

        for (int i=0;i<4;i++) {
            int nr=r+dR[i];
            int nc=c+dC[i];
            if (isValid(nr, nc, i, N, M, factory)) {
                sum = add(sum, dfs(nr, nc, N, M, factory, visited, memo));
                cnt++;
            }
        }

        if (cnt>0) {
            return memo[r][c] = multiply(sum, {1, cnt});
        } else {
            return memo[r][c] = {0, 1};
        }
    }

    return memo[r][c] = {0, 1};
}

pair<long long, long long> solve(int N, int M, vector<string>& factory) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<pair<ll, ll>>> memo(N, vector<pair<ll, ll>>(M));

    return dfs(0, 0, N, M, factory, visited, memo);
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
