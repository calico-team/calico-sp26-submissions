#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll l, w, e, r;
    cin >> l >> w >> e >> r;
    ll power = 2*(l + w)*r;
    cout << (e + power - 1)/power << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}