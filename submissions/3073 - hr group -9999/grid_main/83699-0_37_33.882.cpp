#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    if(n != 3){
        cout << "SIX SEVEN" << endl;
    }
    int a, b, c;
    cin >> a >> b >> c;
    // try avg;
    int bottom = (a + b + c) / 3 - 2;
    int ans = 1e15;
    int fin = 67;
    for(int i = max(0LL, bottom); i <= bottom + 7; i++){
        if(abs(a - b) + abs(c - b) + abs(a - i) + abs(b - i) + abs(c - i) < ans){
            fin = i;
        }
        ans = min(ans, abs(a - b) + abs(c - b) + abs(a - i) + abs(b - i) + abs(c - i));
    }
    if((abs(a - b) + abs(b - c)) * 2 < ans){
        cout << a << " " << b << " " << c << endl;
        return;
    }
    cout << fin << " " << fin << " " << fin << endl;
}
signed main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}