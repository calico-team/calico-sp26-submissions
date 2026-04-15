#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        char s1[n][n]; for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> s1[i][j];
        char s2[n][n]; for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> s2[i][j];
        
        int sm = 0, bg = 0;
        for(int i = 0; i < n; i++){
            int cnt1 = 0;
            for(int j = 0; j < n; j++){
                if(s1[i][j] == '#') cnt1++;
            }
            int cnt2 = 0;
            for(int j = 0; j < n; j++){
                if(s2[i][j] == '#') cnt2++;
            }
            sm += max(cnt1, cnt2);
            bg += cnt1 * cnt2;
        }
        // cout << '>';
        cout << bg << ' ' << sm << endl;
    }
}