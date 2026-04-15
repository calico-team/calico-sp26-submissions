#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    int a[1001] = {0};
    int b[1001] = {0};
    for(int i = 0; i<n; i++){
        string z;
        cin >> z;
        for(char c: z){
            a[i] += (c == '#');
        }
    }
    for(int i = 0; i<n; i++){
        string z;
        cin >> z;
        for(char c: z){
            b[i] += (c == '#');
        }
    }
    int res1 = 0;
    int res2 = 0;
    for(int i = 0; i<n; i++){
        int x = a[i];
        int y = b[i];
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