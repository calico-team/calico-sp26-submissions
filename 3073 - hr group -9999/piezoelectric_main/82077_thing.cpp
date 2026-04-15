#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int l, w, e, r;
        cin >> l >> w >> e >> r;
        e /= r;
        int perimeter = l + w;
        perimeter *= 2;
        cout << e / perimeter << endl;
    }
    return 0;
}