#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

ll hit[1000000];

ll x[100000], y[100000];
vector<pii> ls[1000000]; // i : x

void solve() {
    ll k, n, m, p, q;
    cin>>k>>n>>m>>p>>q;

    for (int i = 0; i < k; i++) {
        cin>>x[i]>>y[i];
        ls[x[i]].emplace_back(y[i], i);
    }

    ll cycle = 1;
    ll v = q % n;
    while(v != 0) {
        cycle++;
        v = (v + q) % n;
    }

    fill(hit, hit + 1000000, -1);
    ll tp = p * cycle % m;
    ll c = 0;
    ll d = 0;
    hit[d] = 0;
    while (true) {
        c++;
        d = (d + tp) % m;
        if (hit[d] != -1) {
            break;
        }
        hit[d] = c;
    }

    ll res = 1e18;
    int ri = -1;

    ll by = (y[0] + p) % m;
    c = 1;
    d = (x[0] + q) % n;
    for (int i = 0; i < cycle; i++) {
        for (auto [cy, i] : ls[d]) {
            cy = (cy + m - by) % m;

            if (hit[cy] != -1) {
                ll curr = c + hit[cy] * cycle;
                if (curr < res) {
                    res = curr;
                    ri = i;
                }
            }
        }

        by = (by + p) % m;
        c++;
        d = (d + q) % n;
    }

    cout << ri << '\n';

    for (int i = 0; i < k; i++) {
        ls[x[i]].clear();
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    
    return 0;
}