#include <iostream>
#include <string>
#include <vector>
using namespace std;

using i64 = long long;
using str = string;
const i64 ILL = 2167167167167167167;
const int INF = 2100000000;

i64 gcd(i64 a, i64 b, i64 &x, i64 &y) {
    if(b == 0) {
        x = 1;y = 0;
        return a;
    }
    i64 x1, y1;
    i64 d = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1-y1*(a/b);
    return d;
}

int main(){
    int t; cin >> t;
    while(t--){
        i64 k;
        i64 n, m, p, q;
        cin >> k >> n >> m >> p >> q;

        vector<pair<i64, i64>> ast(k);
        for(int i=0;i<k;i++){ cin >> ast[i].first >> ast[i].second;}
        i64 x0 = ast[0].first, y0 = ast[0].second;
        i64 minT = ILL;
        int ansIdx = -1;

        for(int i=0;i<k;i++) {
            i64 dx = (ast[i].first - x0) % n; dx += ((dx < 0) ? n : 0);
            i64 dy = (ast[i].second - y0) % m; dy += ((dy < 0) ? m : 0);

            i64 tx, yx, g1 = gcd(q, n, tx, yx);
            if (dx % g1 != 0) continue;
            i64 modX = n / g1;
            i64 valX = (tx % modX) * ((dx / g1) % modX) % modX;
            if (valX < 0) valX += modX;

            i64 ty, yy, g2 = gcd(p, m, ty, yy);
            if (dy % g2 != 0) continue;
            i64 modY = m / g2;
            i64 valY = (ty % modY) * ((dy / g2) % modY) % modY;
            if (valY < 0) valY += modY;

            i64 xCrt, yCrt;
            i64 gCrt = gcd(modX, modY, xCrt, yCrt);
            if ((valY - valX) % gCrt != 0) continue;

            i64 lcm = (modX / gCrt) * modY;
            i64 factor = (valY - valX) / gCrt;
            i64 res = (xCrt % (modY / gCrt)) * (factor % (modY / gCrt)) % (modY / gCrt);
            i64 finalT = (valX + modX * res) % lcm;
            if (finalT < 0) finalT += lcm;

            if (finalT == 0) finalT = lcm;

            if (finalT < minT) {
                minT = finalT;
                ansIdx = i;
            }
        }
        cout << ansIdx << endl;
    }

    return 0;
}