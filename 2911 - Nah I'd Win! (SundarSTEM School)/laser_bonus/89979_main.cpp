#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define ll long long
#define int long long 


int bp(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
};

const int N = 1e6;
 
int spf[N+1];
vector<pair<int, int>> prime_factorize(int x) {
    vector<pair<int, int>> ans;
    while (x > 1) {
        int p = spf[x];
        int exp = 0;
        while (x % p == 0) {
            ++exp;
            x /= p;
        }
        ans.push_back({p, exp});
    }
    return ans;
}
int phi(int x) {
    vector<pair<int, int>> pf = prime_factorize(x);
    int ans = 1;
    for (auto [p, e] : pf) ans = 1LL * ans * (p - 1);
    ans = 1LL * ans * n;
    for (auto [p, e] : pf)
        ans /= p;
    return ans;
}
int inv(int x, int m) {
    int ph = phi(x);
    return bp(x, ph - 1,m);
};


int sol(int k1, int k2, int m1, int m2) {
    int m3 = inv((m2 % m1), m1);
    k2 %= m1;
    k1 %= m1;
    int res = (k1 - k2) * m3;
    int a = m2 * res + k2;
    if (a < 0) a += m1*m2;
    return a;
};

void solve() {
    int k, n, m, p, q; cin >> k >> n >> m >> p >> q;
    vector<pair<int, int>> a(k);
    int min_sat = 1e9;
    int idx = -1;
    for (int i = 0; i < k; i++)
        cin >> a[i].first >> a[i].second;
    int x = a[0].first + q;
    int y = a[0].second + p;
    for (int i = 0; i < k; i++) {
        int tx = a[i].first;
        int ty = a[i].second;
        // x + k * q = tx mod n
        // y + k * p = ty mod m
        int r1 = (tx - x) % n;
        if (r1 < 0) r1 += n;
        int r2 = (ty - y) % m;
        if (r2 < 0) r2 += m;
        //  we want k * q = r1 mod n
        // k * p = r2 mod m 
        int m1 = n;
        int m2 = m;
        int g1 = gcd(q, gcd(r1, m1));
        int g2 = gcd(p, gcd(r2, m2));
        int nq = q;
        int np = p;
        nq /= g1; 
        r1 /= g1;
        m1 /= g1;
        np /= g2;
        r2 /= g2;
        m2 /= g2;
        if (gcd(nq, m1) != 1 || gcd(np, m2) != 1) continue;
        int k1 = r1 * inv(nq,m1) % m1;
        int k2 = r2 * inv(np,m2) % m2;
        if (sol(k1, k2, m1, m2) < min_sat) {
            min_sat = sol(k1, k2, m1, m2);
            idx = i; 
        }
    }
    cout << idx << endl; 
}




signed main() {
    iota(spf, spf+N+1, 0);
    for (int i = 2; i <= N; i++) {
        if (spf[i] != i) continue;
        for (int j = i; j <= N; j += i)
            if (spf[j] == j)
                spf[j] = i;
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) solve();
    return 0;
}
