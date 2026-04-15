#include<bits/stdc++.h>
using namespace std;
char s1[1010][1010];
char s2[1010][1010];
int numrow1[1010];
int numrow2[1010];
int n;
int calcmin(){
    int minans = 0;
    for(int i = 1; i <= n; i++){
        minans += max(numrow1[i], numrow2[i]);
    }
    return minans;
}
int calcmax(){
    int maxans = n*n*n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i][j] == '.') maxans -= n;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s2[i][j] == '.') maxans -= numrow1[i];
        }
    }
    return maxans;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            numrow1[i] = 0;
            numrow2[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> s1[i][j];
                if(s1[i][j] == '#') numrow1[i]++;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> s2[i][j];
                if(s2[i][j] == '#') numrow2[i]++;
            }
        }
        int minans = calcmin();
        int maxans = calcmax();
        cout << maxans << " " << minans << endl;
    }
    return 0;
}