#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

i64 extgcd(i64 a, i64 b, i64 &x, i64 &y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    i64 x1, y1;
    i64 g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

i64 modinv(i64 a, i64 mod){
    i64 x, y;
    extgcd(a, mod, x, y);
    x %= mod;
    if(x < 0) x += mod;
    return x;
}

i64 crt(i64 a1, i64 m1, i64 a2, i64 m2){
    i64 g = gcd(m1, m2);
    if((a2 - a1) % g != 0) return -1;

    i64 l = m1 / g * m2;

    i64 p = m1 / g;
    i64 q = m2 / g;

    i64 inv = modinv(p % q, q);

    i64 t = (a2 - a1) / g % q;
    if(t < 0) t += q;

    t = (t * inv) % q;

    i64 res = (a1 + m1 * t) % l;
    if(res < 0) res += l;
    return res;
}

void solve(){
    int K;
    i64 N, M, P, Q;
    cin >> K >> N >> M >> P >> Q;

    vector<i64> x(K), y(K);
    for(int i = 0; i < K; i++){
        cin >> x[i] >> y[i];
    }

    i64 x0 = x[0], y0 = y[0];

    i64 invQ = modinv(Q % N, N);
    i64 invP = modinv(P % M, M);

    i64 best_t = -1;
    int best_idx = 0;

    for(int i = 0; i < K; i++){
        i64 dx = (x[i] - x0) % N;
        if(dx < 0) dx += N;

        i64 dy = (y[i] - y0) % M;
        if(dy < 0) dy += M;

        i64 t1 = (dx * invQ) % N;
        i64 t2 = (dy * invP) % M;

        i64 t = crt(t1, N, t2, M);
        if(t == -1) continue;

        if(i == 0 && t == 0){
            t = (N / gcd(N, M)) * M;
        }

        if(best_t == -1 || t < best_t){
            best_t = t;
            best_idx = i;
        }
    }

    cout << best_idx << '\n';
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
}