#include <bits/stdc++.h>
using namespace std;

int main() {
    int l,w,e,r,t;
    cin >> t;
    while (t--) {
        cin >> l >> w >> e >> r;
        int p = 2*l+2*w;
        cout << (e+p*r-1)/(p*r) << endl;
    }
}