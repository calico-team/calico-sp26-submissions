#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    long long v;
    double w;
};

struct Target {
    long long val;
    double weight;
    bool operator<(const Target& o) const {
        return val < o.val;
    }
};

struct Constraint {
    int r, c;
    long long v;
    double w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d;
    if (!(cin >> n >> m >> d)) return 0;

    vector<vector<Edge>> adj(n + 1);
    vector<Constraint> edges(m + 1);

    for (int i = 1; i <= m; ++i) {
        int r, c;
        long long v;
        double w;
        cin >> r >> c >> v >> w;
        edges[i] = {r, c, v, w};
        adj[r].push_back({c, v, w});
        adj[c].push_back({r, v, w});
    }

    vector<long long> a(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        if (!adj[i].empty()) {
            double sum = 0;
            for (auto& edge : adj[i]) {
                sum += sqrt(edge.v);
            }
            a[i] = max(1LL, min(1000000000LL, (long long)(sum / adj[i].size())));
        }
    }

    int iterations = 30;
    for (int iter = 0; iter < iterations; ++iter) {
        for (int i = 1; i <= n; ++i) {
            if (adj[i].empty()) continue;
            vector<Target> targets;
            double total_weight = 0;
            for (auto& edge : adj[i]) {
                long long val = max(1LL, (edge.v + a[edge.to] / 2) / a[edge.to]);
                double weight = edge.w * a[edge.to] / (double)edge.v;
                targets.push_back({val, weight});
                total_weight += weight;
            }
            sort(targets.begin(), targets.end());
            double curr = 0;
            long long median = targets.back().val;
            for (auto& t : targets) {
                curr += t.weight;
                if (curr >= total_weight / 2.0) {
                    median = t.val;
                    break;
                }
            }
            a[i] = max(1LL, min(1000000000LL, median));
        }
    }

    vector<pair<double, int>> penalties;
    for (int i = 1; i <= m; ++i) {
        double p = edges[i].w * abs(a[edges[i].r] * a[edges[i].c] - edges[i].v) / (double)edges[i].v;
        penalties.push_back({p, i});
    }

    sort(penalties.rbegin(), penalties.rend());

    for (int i = 1; i <= n; ++i) {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    cout << d;
    for (int i = 0; i < d; ++i) {
        cout << " " << penalties[i].second;
    }
    cout << "\n";

    return 0;
}