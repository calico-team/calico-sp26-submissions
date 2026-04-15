#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    char a[1001][1001];
    char b[1001][1001];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> b[i][j];
        }
    }
    int res1 = 0;
    int res2 = 0;
    for(int i = 0; i<n; i++){
        int x = 0;
        int y = 0;
        for(int j = 0; j<n; j++){
            x += (a[i][j] == '#');
            y += (b[i][j] == '#');
        }
        res1 += max(x, y);
        int c = n-x;
        int d = n-y;
        int e = c * n + d*(n-c);
        res2 += (n*n - e);
    }
    cout << res2 << " " << res1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    
    return 0;
}