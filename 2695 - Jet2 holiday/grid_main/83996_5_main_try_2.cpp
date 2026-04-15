#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll calc(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    ll cost = 0;


    for (int i = 0; i < n; i++) {
        cost += abs(a[i] - b[i]);
    }


    for (int i = 0; i < n-1; i++) {
        cost += abs(b[i] - b[i+1]);
    }

    return cost;
}


vector<int> solve(int n, vector<int>& a) {
    vector<int> best_b;
    ll min_cost = 1e18;


    vector<int> cands = a;


    if (n == 1) {
        for (int x : cands) {
            vector<int> b = {x};
            ll c = calc(a, b);
            if (c < min_cost) {
                min_cost = c;
                best_b = b;
            }
        }
    }
    else if (n == 2) {
        for (int x : cands)
        for (int y : cands) {
            vector<int> b = {x, y};
            ll c = calc(a, b);
            if (c < min_cost) {
                min_cost = c;
                best_b = b;
            }
        }
    }
    else if (n == 3) {
        for (int x : cands)
        for (int y : cands)
        for (int z : cands) {
            vector<int> b = {x, y, z};
            ll c = calc(a, b);
            if (c < min_cost) {
                min_cost = c;
                best_b = b;
            }
        }
    }

    return best_b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        auto b = solve(n, a);
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}