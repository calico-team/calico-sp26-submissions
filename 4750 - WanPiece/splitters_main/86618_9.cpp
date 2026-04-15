#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

#define pii pair<int, int>
#define int long long

#define fi first
#define se second

int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

pii add(pii a, pii b){
    if(a.se == b.se) return {a.fi + b.fi, a.se};
    int tar = lcm(a.se, b.se);
    a.fi *= tar / a.se;
    b.fi *= tar / b.se;

    int sm = a.fi + b.fi;

    int div = __gcd(tar, sm);
    sm /= div;
    tar /= div;

    return {sm, tar};
}

pii simp(pii a){
    int div = __gcd(a.fi, a.se);
    return {a.fi / div, a.se / div};
}

void solve(){

    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    for(auto &i : arr) cin >> i;

    vector<vector<int>> avail(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != '.' && arr[i][j] != 'X'){
                if(i > 0 && ((arr[i - 1][j] == 'S' && arr[i][j] != '^') || arr[i - 1][j] == 'v')) avail[i][j]++;
                if(i < n - 1 && ((arr[i + 1][j] == 'S' && arr[i][j] != 'v') || arr[i + 1][j] == '^')) avail[i][j]++;
                if(j > 0 && ((arr[i][j - 1] == 'S' && arr[i][j] != '<') || arr[i][j - 1] == '>')) avail[i][j]++;
                if(j < m - 1 && ((arr[i][j + 1] == 'S' && arr[i][j] != '>') || arr[i][j + 1] == '<')) avail[i][j]++;
            }
        }
    }

    vector<vector<pii>> ans(n, vector<pii>(m, make_pair(0, 1)));

    queue<pii> q;
    q.push({0, 0});

    ans[0][0] = {1, 1};

    avail[0][0]--;

    pii ret = {0, 1};

    // for(auto i : avail){
    //     for(auto j : i){
    //         cout << j << ' ';
    //     } cout << endl;
    // }

    while(!q.empty()){

        auto [x, y] = q.front();
        q.pop();
        avail[x][y]--;

        // cout << x << ' ' << y << ' ' << ans[x][y].fi << ' ' << ans[x][y].se << endl;

        if(arr[x][y] == '^'){
            if(x == 0){
                ret = add(ret, ans[x][y]);
                break;
            }
            ans[x - 1][y] = add(ans[x - 1][y], ans[x][y]);
            avail[x - 1][y]--;
            if(avail[x - 1][y] == 0){
                q.push({x - 1, y});
            }
        }

        if(arr[x][y] == 'v'){
            if(x == n - 1){
                ret = add(ret, ans[x][y]);
                break;
            }
            ans[x + 1][y] = add(ans[x + 1][y], ans[x][y]);
            avail[x + 1][y]--;
            if(avail[x + 1][y] == 0){
                q.push({x + 1, y});
            }
        }

        if(arr[x][y] == '<'){
            if(y == 0){
                ret = add(ret, ans[x][y]);
                break;
            }
            ans[x][y - 1] = add(ans[x][y - 1], ans[x][y]);
            avail[x][y - 1]--;
            if(avail[x][y - 1] == 0){
                q.push({x, y - 1});
            }
        }

        if(arr[x][y] == '>'){
            if(y == m - 1){
                ret = add(ret, ans[x][y]);
                break;
            }
            ans[x][y + 1] = add(ans[x][y + 1], ans[x][y]);
            avail[x][y + 1]--;
            if(avail[x][y + 1] == 0){
                q.push({x, y + 1});
            }
        }

        if(arr[x][y] == 'S'){
            int cnt = 0;
            if(arr[x - 1][y] != 'v' && arr[x - 1][y] != '.') avail[x - 1][y]--, cnt++;
            if(arr[x + 1][y] != '^' && arr[x + 1][y] != '.') avail[x + 1][y]--, cnt++;
            if(arr[x][y + 1] != '<' && arr[x][y + 1] != '.') avail[x][y + 1]--, cnt++;
            if(arr[x][y - 1] != '>' && arr[x][y - 1] != '.') avail[x][y - 1]--, cnt++;

            ans[x][y].se *= cnt;
            ans[x][y] = simp(ans[x][y]);
            
            if(arr[x - 1][y] != 'v'){
                ans[x - 1][y] = add(ans[x - 1][y], ans[x][y]);
                if(avail[x - 1][y] == 0) q.push({x - 1, y});
            }
            if(arr[x + 1][y] != '^'){
                ans[x + 1][y] = add(ans[x + 1][y], ans[x][y]);
                if(avail[x + 1][y] == 0) q.push({x + 1, y});
            }
            if(arr[x][y + 1] != '<'){
                ans[x][y + 1] = add(ans[x][y + 1], ans[x][y]);
                if(avail[x][y + 1] == 0) q.push({x, y + 1});
            }
            if(arr[x][y - 1] != '>'){
                ans[x][y - 1] = add(ans[x][y - 1], ans[x][y]);
                if(avail[x][y - 1] == 0) q.push({x, y - 1});
            }
        }
    }

    cout << ret.fi << ' ' << ret.se << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;
    cin >> tc;
    while(tc--) solve();

}