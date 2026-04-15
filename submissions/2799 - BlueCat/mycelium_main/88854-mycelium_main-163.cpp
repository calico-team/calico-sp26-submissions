#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        xg += 40;
        yg += 40;
        xm += 40;
        ym += 40;
        long long ans = 0;
        
        vector<vector<int>> arr(100, vector<int>(100, -1));
        arr[xg][yg] = 1;
        int curG, curM;
        curG = 1;
        curM = 2;
        arr[xm][ym] = 2;

        for(int t = 1; t <= 220; t++){
            if(t%2 == 0){
                for(int i = 0; i < 100; i++){
                    for(int j = 0; j < 100; j++){
                        if(arr[i][j] == curG){
                            if(i > 0 && arr[i-1][j] == -1) arr[i-1][j] = curG+2;
                            if(i < 99 && arr[i+1][j] == -1) arr[i+1][j] = curG+2;
                            if(j > 0 && arr[i][j-1] == -1) arr[i][j-1] = curG+2;
                            if(j < 99 && arr[i][j+1] == -1) arr[i][j+1] = curG+2;
                        }
                    }
                }
                curG += 2;
            }
            if(t%7 == 0){
                for(int i = 0; i < 100; i++){
                    for(int j = 0; j < 100; j++){
                        if(arr[i][j] == curM){
                            if(i > 0 && arr[i-1][j] == -1) arr[i-1][j] = curM+2;
                            if(i < 99 && arr[i+1][j] == -1) arr[i+1][j] = curM+2;
                            if(j > 0 && arr[i][j-1] == -1) arr[i][j-1] = curM+2;
                            if(j < 99 && arr[i][j+1] == -1) arr[i][j+1] = curM+2;
                        }
                    }
                }
                curM += 2;
            }
        }

        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                if(arr[i][j] != -1 && arr[i][j]%2 == 0) ans++;
            }
        }
        cout << ans << "\n";


    }
}