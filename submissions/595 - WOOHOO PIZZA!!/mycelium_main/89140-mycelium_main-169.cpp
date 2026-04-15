/*
*/

#include <bits/stdc++.h>
// #define int long long
#define setmax(a, b) a = std::max(a,b);
#define setmin(a, b) a = std::min(a,b);
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = a; i >= (b); --i)
const int INF = std::numeric_limits<int>::max()/20;
using namespace std;

vector<array<int,2>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        array<int,2> g,m;
        cin >> g[0]>>g[1]>>m[0]>>m[1];
        g[0]-=m[0],g[1]-=m[1];
        m[0]=250,m[1]=250,g[0]+=250,g[1]+=250;
        vector<vector<int>> a(500, vector<int>(500));
        priority_queue<array<int,4>, vector<array<int,4>>, greater<>> pq;
        // a[g[0]][g[1]] = -1;
        // a[m[0]][m[1]] = 1;
        pq.push({0,0,g[0],g[1]});
        pq.push({0,1,m[0],m[1]});
        while (!pq.empty()) {
            auto [t,type,i,j] = pq.top(); pq.pop();
            // array<int,2> p = {i,j};
            if (a[i][j]) continue;
            a[i][j] = max(t,1) * (type ? 1 : -1);
            if (t >= 200) break;;
            for (auto& [x,y] : dir) {
                int ni = i+x, nj = j+y;
                int nt = t+(type ? 7 : 2);
                if (ni >= 0 && ni < 500 && nj >= 0 && nj < 500) {
                    if (a[ni][nj]) continue;
                    pq.push({nt,type,ni,nj});
                }
            }
        }
        int ans = 0;
        for (auto& v : a) for (auto x : v) {
            if (x > 0) ++ans;
        } 
        cout << ans << '\n';
    }   
    return 0;
}