#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<pi, ll> pii;

vector<pi> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool checkValid(int dr, int dc, char c){
    if (c == '.') return false;
    if (dr == 1 && c == '^') return false;
    if (dr == -1 && c == 'v') return false;
    if (dc == -1 && c == '>') return false;
    if (dc == 1 && c == '<') return false;
    return true;
}

pair<ll, ll> addFrac(vector<ll>& denoms){
    ll num = 0, denom = 1;
    for (int d : denoms){
        num = num*d + denom;
        denom *= d;
        long long g = gcd(num, denom);
        num /= g;
        denom /= g;
    }
    return {num, denom};
}

void solve(){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    if (grid[0][0] == 'X'){
        cout << "0 1" << "\n";
        return;
    }
    vector<ll> collect;
    queue<pii> q;
    q.push({{0, 0}, 1});
    while (!q.empty()){
        auto [coords, denom] = q.front(); q.pop();
        auto [r, c] = coords;
        char cur = grid[r][c];
        if (cur == 'S'){
            int split = 0;
            for (auto [dr, dc] : dirs){
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                split += checkValid(dr, dc, grid[nr][nc]);
            }
            for (auto [dr, dc] : dirs){
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (!checkValid(dr, dc, grid[nr][nc])) continue;
                q.push({{nr, nc}, denom*split});
            }
        }
        else {
            if (r == 0 && cur == '^') collect.push_back(denom);
            else if (r == n-1 && cur == 'v') collect.push_back(denom);
            else if (c == 0 && cur == '<') collect.push_back(denom);
            else if (c == m-1 && cur == '>') collect.push_back(denom);
            else if (cur == '^') q.push({{r-1, c}, denom});
            else if (cur == 'v') q.push({{r+1, c}, denom});
            else if (cur == '<') q.push({{r, c-1}, denom});
            else if (cur == '>') q.push({{r, c+1}, denom});
        }
    }
    if (collect.size() == 0){
        cout << "0 1" << "\n";
        return;
    }
    auto [num, denom] = addFrac(collect);
    cout << num << " " << denom << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}