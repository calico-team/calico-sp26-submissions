#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int, int>

bool inMap(int x, int y){
    if(x < 0 || x > 1000) return false;
    if(y < 0 || y > 1000) return false;
    return true;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve(){

    vector<vector<int>> vis(1001, vector<int>(1001));

    int xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;

    xg += 200;
    yg += 200;
    xm += 200;
    ym += 200;

    queue<pii> grass;
    queue<pii> moss;

    grass.push({xg, yg});
    moss.push({xm, ym});

    vis[xg][yg] = 1;
    vis[xm][ym] = 2;

    int epoch = 1;

    while(!grass.empty() && !moss.empty()){

        if(epoch % 2 == 0){

            queue<pii> pend;

            while(!grass.empty()){
                auto [x, y] = grass.front();
                grass.pop();
                for(int i = 0; i < 4; i++){
                    int X = x + dx[i];
                    int Y = y + dy[i];
                    if(inMap(X, Y) && !vis[X][Y]){
                        vis[X][Y] = 1;
                        pend.push({X, Y});
                    }
                }
            }

            while(!pend.empty()){
                grass.push(pend.front());
                pend.pop();
            }

        }

        if(epoch % 7 == 0){

            queue<pii> pend;

            while(!moss.empty()){
                auto [x, y] = moss.front();
                moss.pop();
                for(int i = 0; i < 4; i++){
                    int X = x + dx[i];
                    int Y = y + dy[i];
                    if(inMap(X, Y) && !vis[X][Y]){
                        vis[X][Y] = 2;
                        pend.push({X, Y});
                    }
                }
            }

            while(!pend.empty()){
                moss.push(pend.front());
                pend.pop();
            }

        }

        epoch++;

    }

    int ret = 0;

    for(auto i : vis){
        for(auto j : i){
            if(j == 2) ret++;
        }
    }

    cout << ret << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;
    cin >> tc;
    while(tc--) solve();

}