#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair <int, int> PI;

const int N = 5e2 + 7;

int occ[N][N], tmp[N][N];

vector <PI> a[N][N];

int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

struct str{
    int x, y;
};

queue <str> qu;

int t, n, s1, s2, e1, e2;

signed main(){

    cin >> t;

    while(t --){

        cin >> s1 >> s2 >> e1 >> e2;
        s1 += 200, s2 += 200, e1 += 200, e2 += 200;
        memset(occ, 0, sizeof(occ));
        int cnt = 1;
        occ[s1][s2] = 1, occ[e1][e2] = 2;
        for(int tms = 1; tms <= 100; tms ++){
            int nw = 0;
            if(tms % 14 == 0){
                memcpy(tmp, occ, sizeof(occ));
                for(int i = 1; i <= 400; i ++){
                    for(int j = 1; j <= 400; j ++){
                        if(!tmp[i][j]) continue;
                        occ[i][j] = tmp[i][j];
                        for(int k = 0; k < 4; k ++){
                            int nx = i + dx[k], ny = j + dy[k];
                            if(tmp[nx][ny]) continue;
                            if(tmp[i][j] == 1) occ[nx][ny] = 1;
                            else if(occ[nx][ny] != 1) occ[nx][ny] = 2;
                        }
                    }
                }
                for(int i = 1; i <= 400; i ++)
                    for(int j = 1; j <= 400; j ++)
                        nw += occ[i][j] == 2;
                if(nw == cnt) break;
                else cnt = nw;
            }
            else if(tms % 2 == 0){
                memcpy(tmp, occ, sizeof(occ));
                for(int i = 1; i <= 400; i ++){
                    for(int j = 1; j <= 400; j ++){
                        if(tmp[i][j] != 1) continue;
                        occ[i][j] = tmp[i][j];
                        for(int k = 0; k < 4; k ++){
                            int nx = i + dx[k], ny = j + dy[k];
                            if(tmp[nx][ny]) continue;
                            occ[nx][ny] = 1;
                        }
                    }
                }
            }
            else if(tms % 7 == 0){
                memcpy(tmp, occ, sizeof(occ));
                for(int i = 1; i <= 400; i ++){
                    for(int j = 1; j <= 400; j ++){
                        if(tmp[i][j] != 2) continue;
                        // cout << i << ' ' << j << " ::: ";
                        occ[i][j] = tmp[i][j];
                        for(int k = 0; k < 4; k ++){
                            int nx = i + dx[k], ny = j + dy[k];
                            if(tmp[nx][ny]) continue;
                            // cout << "** " << nx << ' ' << ny << " **";
                            occ[nx][ny] = 2;
                        }
                    }
                }
                for(int i = 1; i <= 400; i ++)
                    for(int j = 1; j <= 400; j ++){
                        nw += (occ[i][j] == 2);
                        // if(occ[i][j] == 2) cout << i - 200 << ' ' << j - 200 << " / ";
                    }
                // cout << endl;
                if(nw == cnt) break;
                else cnt = nw;
            }
            // for(int i = 1; i <= 400; i ++){
            //     for(int j = 1; j <= 400; j ++)
            //         cout << occ[i][j];
            //     cout << endl;
            // }
            // cout << endl << endl << endl;
            // cout << tms << ": " << cnt << " / ";
        }

        cout << cnt << endl;
        
    }

    return 0;
}

