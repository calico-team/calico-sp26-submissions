#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector<long long> x(k);
        vector<long long> y(k);
        for(int i = 0; i < k; i++){
            cin >> x[i] >> y[i];
        }
        long long ans = -1;
        long long val = -1;
        for(int i = 0; i < k; i++){
            long long dx = (x[i] - x[0]) % n;
            long long dy = (y[i] - y[0]) % m;
            if(dx < 0) dx += n;
            if(dy < 0) dy += m;
            long long u1;
            long long v1;
            long long g1 = gcd(q, n, u1, v1);
            if(dx % g1 != 0){
                continue;
            }
            long long n1 = n/g1;
            long long t1 = (dx/g1 % n1);
            t1 = (t1 * u1) % n1;
            if(t1 < 0) t1 += n1;
            long long u2;
            long long v2;
            long long g2 = gcd(p, m, u2, v2);
            if(dy % g2 != 0){
                continue;
            }
            long long m1 = m/g2;
            long long t2 = (dy/g2 % m1);
            t2 = (t2 * u2) % m1;
            if(t2 < 0) t2 += m1;
            long long u3;
            long long v3;
            long long g3 = gcd(n1, m1, u3, v3);
            long long diff = ((t2 - t1) % m1 + m1) % m1;
            if(diff % g3 != 0){
                continue;
            }
            long long m2 = m1/g3;
            long long t3 = (diff/g3 % m2);
            t3 = (t3 * u3) % m2;
            if(t3 < 0) t3 += m2;
            long long val9 = n1 * m2;
            long long cur = (t1 + t3 * n1) % val9;
            if(cur == 0){
                cur = val9;
            }
            if(val == -1 || cur < val){
                val = cur;
                ans = i;
            }
        }
        cout << ans << "\n";
    }
}