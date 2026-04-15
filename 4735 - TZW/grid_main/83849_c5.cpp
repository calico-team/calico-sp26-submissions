#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cost(const vector<ll>& a, const vector<ll>& b) {
    int n = a.size();
    ll res = 0;
    for (int i = 0; i < n - 1; i++) {
        res += abs(a[i] - a[i+1]);
        res += abs(b[i] - b[i+1]);
    }
    for (int i = 0; i < n; i++) {
        res += abs(a[i] - b[i]);
    }
    return res;
}

vector<ll> solvesmall(const vector<ll>& a) {
    int n = a.size();
    vector<ll> bestb(n);
    ll bestcost = LLONG_MAX;

    set<ll> candidates;
    for (ll x : a) {
        for (ll d = -2; d <= 2; d++) {
            candidates.insert(x + d);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll avg = (a[i] + a[j]) / 2;
            for (ll d = -2; d <= 2; d++) {
                candidates.insert(avg + d);
            }
        }
    }
    candidates.insert(1);
    candidates.insert(2000000000);

    vector<ll> cand(candidates.begin(), candidates.end());

    function<void(int, vector<ll>&)> dfs = [&](int idx, vector<ll>& cur) {
        if (idx == n) {
            ll c = cost(a, cur);
            if (c < bestcost) {
                bestcost = c;
                bestb = cur;
            }
            return;
        }
        for (ll val : cand) {
            cur[idx] = val;
            dfs(idx + 1, cur);
        }
    };

    vector<ll> cur(n);
    dfs(0, cur);
    return bestb;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<ll> b;
        if (n <= 3) {
            b = solvesmall(a);
        } else {
            b = a;
        }

        for (int i = 0; i < n; i++) {
            cout << b[i] << (i == n-1 ? "\n" : " ");
        }
    }
    return 0;
}