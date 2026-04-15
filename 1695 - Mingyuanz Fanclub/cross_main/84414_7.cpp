#include <bits/stdc++.h>
using namespace std;
#define pii array<int,2>
#define tii array<int,3>
void think(){
    int m, n;
    cin >> m >> n;
    int dp = 0;
    for(int i = 0; i < m; i++){
        int cur = dp;
        for(int j = 0; j < n; j++){
            cout << cur << ' ';
            cur = (cur+1)%5;
        }
        dp = (dp + 2) % 5;
        cout << '\n';
    }
}
int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--){
        think();
    }
}