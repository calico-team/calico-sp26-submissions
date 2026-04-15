#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        char s1[n][n]; int cnt1[n] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> s1[i][j];
                if(s1[i][j] == '#') cnt1[i]++;
            }
        }
        char s2[n][n]; int cnt2[n] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> s2[i][j];
                if(s2[i][j] == '#') cnt2[i]++;
            }
        }
        int bg = 0, sm = 0;
        for(int i = 0; i < n; i++){
            bg += cnt1[i] * cnt2[i];
            sm += max(cnt1[i], cnt2[i]);
        }
        // cout << '>';
        cout << bg << ' ' << sm << '\n';
    }
}