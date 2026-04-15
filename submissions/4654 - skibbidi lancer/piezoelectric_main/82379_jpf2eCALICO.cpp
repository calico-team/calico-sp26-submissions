
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
void solve (){
    int l, w, e, r;
    cin >> l >> w >> e >> r;
    int perim = ((2*l) + (2*w));
    cout << e/(r*perim) << "\n";
}
int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
