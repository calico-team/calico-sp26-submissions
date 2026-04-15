#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

typedef long long ll;
using namespace std;

/** 
 * Find the index of the first asteroid hit by the laser.
 *         
 * K: Number of asteroids
 * N, M: Bounds for x- and y-coordinates
 * P, Q: Laser movement (P along y-axis, Q along x-axis)
 * X: List of x-coordinates of asteroids
 * Y: List of y-coordinates of asteroids
 */
void egcd(ll a, ll b, ll &x, ll &y) {
    if (b==0) {
        x=1;
        y=0;
        return;
    }
    ll x1, y1;
    egcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
}

pair<ll, ll> getC(ll a, ll b, ll m) {
    ll g = gcd(a, m);
    if (b%g!=0)return{-1, -1};

    ll newA = a/g;
    ll newB = b/g;
    ll newM = m/g;

    ll x,y;
    egcd(newA, newM, x, y);
    ll res = (x%newM + newM) % newM;
    ll ans = (newB % newM * res) % newM;

    return {ans, newM};
}

pair<ll, ll> combine(ll a, ll m1, ll b, ll m2) {
    ll tempB = (b-a)%m2;
    if (tempB<0) tempB+=m2;

    pair<ll, ll> res = getC(m1, tempB, m2);
    if (res.first == -1) return {-1, -1};

    ll temp = lcm(m1, m2);

    ll t = (a+res.first*m1)%temp;
    if (t<0) t+=temp;

    return {t, temp};
}

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
    ll minT = 2e18;
    int idx = -1;

    for (int i=0;i<K;i++) {
        ll dx = (X[i] - X[0]) % N;
        if (dx<0) dx+=N;

        ll dy = (Y[i] - Y[0]) % M;
        if (dy<0) dy+=M;

        pair<ll, ll> rx = getC(Q, dx, N);
        if (rx.first == -1)continue;

        pair<ll, ll> ry = getC(P, dy, M);
        if (ry.first == -1)continue;

        pair<ll, ll> final = combine(rx.first, rx.second, ry.first, ry.second);
        if (final.first == -1) continue;

        ll t= final.first;
        if (t==0) t = final.second;

        if (t<minT) {
            minT = t;
            idx = i;
        }
    }
    return idx;
}


int main() {
    int T; cin >> T;
    while (T--) {
        int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
        vector<int> X(K), Y(K);
        for (int i = 0; i < K; i++) {
            int a, b; cin >> a >> b;
            X[i] = a;
            Y[i] = b;
        }
        cout << solve(K, N, M, P, Q, X, Y) << endl;
    }
    return 0;
}