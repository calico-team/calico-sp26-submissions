#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int l,w,e,r;
        cin >> l >> w >> e >> r;
        cout << ((2*l+2*w)*r)/e << endl;
    }
    return 0;
}