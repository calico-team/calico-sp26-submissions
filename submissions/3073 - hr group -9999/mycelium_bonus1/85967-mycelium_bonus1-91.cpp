#include <bits/stdc++.h>
using namespace std;
#define int long long
short arr[750][750];
void solve(){
    int xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    xg += 375;
    yg += 375;
    xm += 375;
    ym += 375;
    for(int i = 0; i < 750; i++){
        for(int j = 0; j < 750; j++){
            arr[i][j] = -1;
        }
    }
    // grass = 0;
    // myc = 1;
    arr[xg][yg] = 0;
    //cout << xg << " " << yg << endl;
    //cout << xm << " " << ym << endl;
    arr[xm][ym] = 1;
    for(int x = 1; x < 1600; x++){
        if(x % 2 == 0){
            // cout << "Spread grass : " << x << endl;
            // grass
            vector<pair<int, int>> add;
            for(int j = 0; j < 750; j++){
                for(int k = 0; k < 750; k++){
                    if(arr[j][k] != 0){
                        continue;
                    }
                    if(j + 1 < 750 and arr[j + 1][k] == -1){
                        add.push_back({j + 1, k});
                    }
                    if(j - 1 >= 0 and arr[j - 1][k] == -1){
                        add.push_back({j - 1, k});
                    }
                    if(k + 1 < 750 and arr[j][k + 1] == -1){
                        add.push_back({j, k + 1});
                    }
                    if(k - 1 >= 0 and arr[j][k - 1] == -1){
                        add.push_back({j, k - 1});
                    }
                }
            }
            for(int i = 0; i < add.size(); i++){
                if(x == 2){
                    //cout << add[i].first << " " << add[i].second << endl;
                }
                arr[add[i].first][add[i].second] = 0;
            }
        }
        if(x % 7 == 0){
            // myc
            vector<pair<int, int>> add;
            for(int j = 0; j < 750; j++){
                for(int k = 0; k < 750; k++){
                    if(arr[j][k] != 1){
                        continue;
                    }
                    if(j + 1 < 750 and arr[j + 1][k] == -1){
                        add.push_back({j + 1, k});
                    }
                    if(j - 1 >= 0 and arr[j - 1][k] == -1){
                        add.push_back({j - 1, k});
                    }
                    if(k + 1 < 750 and arr[j][k + 1] == -1){
                        add.push_back({j, k + 1});
                    }
                    if(k - 1 >= 0 and arr[j][k - 1] == -1){
                        add.push_back({j, k - 1});
                    }
                }
            }
            for(int i = 0; i < add.size(); i++){
                arr[add[i].first][add[i].second] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 750; i++){
        for(int j = 0; j < 750; j++){
            if(arr[i][j] == 1){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
signed main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}