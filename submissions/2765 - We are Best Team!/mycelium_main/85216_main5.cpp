#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        long long xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;

        long long d = llabs(xg - xm) + llabs(yg - ym);
        long long r = (d - 1) / 5;
        cout << 1 + 2 * r * (r + 1) << '\n';
    }
}