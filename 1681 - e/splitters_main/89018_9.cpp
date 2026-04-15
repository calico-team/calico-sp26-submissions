#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

struct Frac {
    ll p, q;
    
    Frac(ll _p = 0, ll _q = 1) {
        p = _p; 
        q = _q;
        reduce();
    }
    
    void reduce() {
        ll g = gcd(p, q);
        p /= g;
        q /= g;
        if (q < 0) {
            p = -p;
            q = -q;
        }
    }
    
    Frac operator+(const Frac& o) const {
        ll num = p * o.q + o.p * q, den = q * o.q;
        return Frac(num, den);
    }
    
    Frac operator/(ll k) const {
        return Frac(p, q * k);
    }
};

Frac dfs(ll r, ll c, ll N, ll M, const vector<string>& factory, vector<vector<bool>>& visited, vector<vector<Frac>>& memo) {
    if (r < 0 || r >= N || c < 0 || c >= M) {
        return Frac(1, 1);
    }
    
    if (visited[r][c]) {
        return memo[r][c];
    }
    
    visited[r][c] = true;
    char ch = factory[r][c];
    Frac res(0, 1);

    if (ch == 'X') {
        res = Frac(0, 1); 
    } 
    else if (ch == '^') res = dfs(r - 1, c, N, M, factory, visited, memo);
    else if (ch == 'v') res = dfs(r + 1, c, N, M, factory, visited, memo);
    else if (ch == '<') res = dfs(r, c - 1, N, M, factory, visited, memo);
    else if (ch == '>') res = dfs(r, c + 1, N, M, factory, visited, memo);
    else if (ch == 'S') {
        vector<pair<ll, ll>> valid;
        
        if (r - 1 >= 0) {
            char nc = factory[r - 1][c];
            if (nc == 'X' || nc == '^' || nc == '<' || nc == '>') valid.push_back({r - 1, c});
        }
        if (r + 1 < N) {
            char nc = factory[r + 1][c];
            if (nc == 'X' || nc == 'v' || nc == '<' || nc == '>') valid.push_back({r + 1, c});
        }
        if (c - 1 >= 0) {
            char nc = factory[r][c - 1];
            if (nc == 'X' || nc == '^' || nc == 'v' || nc == '<') valid.push_back({r, c - 1});
        }
        if (c + 1 < M) {
            char nc = factory[r][c + 1];
            if (nc == 'X' || nc == '^' || nc == 'v' || nc == '>') valid.push_back({r, c + 1});
        }

        Frac sum(0, 1);
        for (auto& p : valid) {
            sum = sum + dfs(p.first, p.second, N, M, factory, visited, memo);
        }
        if (!valid.empty()) {
            res = sum / (ll)valid.size();
        }
    }
    
    memo[r][c] = res;
    return res;
}

/**
 * Simulate the factory and return the final output as the fraction P / Q.
 *
 * N: number of rows in the factory grid
 * M: number of columns in the factory grid
 * factory: vector of N strings of length M, each character one of '^<>vSX.'
 */
pair<long long, long long> solve(ll N, ll M, vector<string>& factory) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<Frac>> memo(N, vector<Frac>(M));

    Frac ans = dfs(0, 0, N, M, factory, visited, memo);
    
    return {(long long)ans.p, (long long)ans.q};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    while (T--) {
        ll N, M;
        cin >> N >> M;
        vector<string> factory(N);
        for (ll i = 0; i < N; i++) cin >> factory[i];
        auto [P, Q] = solve(N, M, factory);
        cout << P << " " << Q << "\n";
    }
    return 0;
}