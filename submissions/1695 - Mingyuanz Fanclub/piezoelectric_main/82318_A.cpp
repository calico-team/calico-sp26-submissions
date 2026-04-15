#include <bits/stdc++.h>
using namespace std;
#define pii array<int,2>
#define tii array<int,3>
void think(){
    int l, w, e, r;
    cin >> l >> w >> e >> r;
    int dp = 2*(l+w) * r;
    cout << e / dp << '\n';
}
int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--){
        think();
    }
}