#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int l, w, e, r;
        cin >> l >> w >> e >> r;
        int p = (l+w)*2;
        cout << e/(r*p) << endl;
    }
    return 0;
}