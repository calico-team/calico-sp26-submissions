#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int l, w, e, r;
        cin >> l >> w >> e >> r;
        cout << e/(r * 2 * (l + w)) << "\n";
    }
}