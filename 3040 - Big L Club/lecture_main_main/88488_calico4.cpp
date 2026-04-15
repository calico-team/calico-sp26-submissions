#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, S;

int query(vector<vector<int>>& p, int x2, int y2, int x1, int y1){
    return p[x2][y2] - p[x1-1][y2] - p[x2][y1-1] + p[x1-1][y1-1];
}

bool works(vector<vector<int>>& p, int d){

    for(int a = 1; a + d <= S; ++a)
        for(int b = 1; b + d <= S; ++b)
            if(query(p, a+d, b+d, a, b) >= k)
                return true;


    return false;
}

void solve(){
    cin >> n >> m >> k;
    S = n + m + 1;

    char c;

    vector<vector<int>> p(S+2, vector<int>(S+2));
    vector<pair<int,int>> pos;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c;
            if(c == '-'){
                int a = i+j+1, b = i-j+m;

                p[a][b]++;

                pos.push_back({i, j});
            }
        }
    }

    for(int i = 1; i <= S; ++i)
        for(int j = 1; j <= S; ++j)
            p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];


    int D = 0, hi = 2*S-2;

    while(D < hi){
        int mid = D + (hi-D)/2;
        if(works(p, mid)) hi = mid;
        else D = mid + 1;
    }

    for(int a = 1; a + D <= S; a++){
        for(int b = 1; b + D <= S; b++){
            if(query(p,a+D,b+D,a,b) < k) continue;

            int cnt = 0;

            //only find first k

            for(int i = 0; i < pos.size(); ++i){
                int r = pos[i].first, c = pos[i].second;
                int ra = r+c+1, rb = r-c+m;

                if((ra >= a && ra <= a+D) && (rb >= b && rb <= b+D)){
                    cout << r << " " << c << "\n";
                    
                    ++cnt;

                    if(cnt == k){
                        return;
                    }
                }
            }
        }
    }

    // DISH WHAT R U SAYINGNGNGINGIN


    // [x2,y2] x [x1,y1] -> int query = p[x2][y2] - p[x1-1][y2] - p[x2][y1-1] + p[x1-1][y1-1];
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--) solve();
}