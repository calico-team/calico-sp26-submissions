#include <bits/stdc++.h>
using namespace std;

long long X_G, Y_G;
long long X0_bp, X0L_bp, Y0_bp, Y0B_bp;
bool check(long long x, long long y){
    long long dG = 0;
    
    
    if (x >= 0 && y >= 0){
        dG = abs(X_G - x) + abs(Y_G - y);
    }else if (x < 0 && y >= 0) {
     
        long long bypass_y = max(y, Y0_bp);
        dG = X_G + abs(Y_G - bypass_y) + max(0LL, Y0_bp - y) + abs(x);
    }else if (x >= 0 && y < 0) {
    
        long long bypass_x = max(x, X0_bp);
        dG = Y_G + abs(X_G - bypass_x) + max(0LL, X0_bp - x) + abs(y);
    } else {

        long long dA = X_G + abs(Y_G - Y0_bp) + (Y0_bp + abs(y)) + max(0LL, X0L_bp - abs(x)) + abs(x);
        long long dB = Y_G + abs(X_G - X0_bp) + (X0_bp + abs(x)) + max(0LL, Y0B_bp - abs(y)) + abs(y);
        dG = min(dA, dB);
    }
    return 7LL * (abs(x) + abs(y)) < 2LL * dG;
}



void solve(){
    long long xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    
    X_G = abs(xg - xm);
    Y_G = abs(yg - ym);
    

    X0_bp = 0;  while (7LL * X0_bp < 2LL * (abs(X_G - X0_bp) + Y_G)) X0_bp++;
    X0L_bp = 0; while (7LL * X0L_bp < 2LL * (X_G + X0L_bp + Y_G)) X0L_bp++;
    Y0_bp = 0; while (7LL * Y0_bp < 2LL * (X_G + abs(Y_G - Y0_bp))) Y0_bp++;
    Y0B_bp = 0;while (7LL * Y0B_bp < 2LL * (X_G + Y_G + Y0B_bp)) Y0B_bp++;
    
    long long total_area = 0;
    long long xr = 0, xl = 0;
    
    for (long long y = Y0_bp; y >= -Y0B_bp; y--){
        if (!check(0, y)) {
            xr = -1; xl = 1;
            continue;
       }
        if (xr < 0) xr = 0;
        if (xl > 0) xl = 0;
        
        while (check(xr + 1, y)) xr++;
        while (xr >= 0 && !check(xr, y)) xr--;

        while (check(xl - 1, y)) xl--;
        while (xl <= 0 && !check(xl, y)) xl++;
        
        if (xr >= 0 && xl <= 0){
            total_area += (xr - xl + 1);
    }
}
    cout <<total_area << "\n";
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T){
        while (T--){
            solve();
        }
    }
    return 0;
}