#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    int r, c, a, v;
};

struct Fenwick {
    int n = 0;
    int bitMask = 0;
    vector<int> cnt;
    vector<ll> sum;

    Fenwick() = default;
    explicit Fenwick(int maxValue) { init(maxValue); }

    void init(int maxValue) {
        n = maxValue + 1;
        cnt.assign(n + 1, 0);
        sum.assign(n + 1, 0);
        bitMask = 1;
        while (bitMask <= n) bitMask <<= 1;
        bitMask >>= 1;
    }

    void addVal(int value, int deltaCount) {
        int i = value + 1;
        ll deltaSum = 1LL * deltaCount * value;
        for (; i <= n; i += i & -i) {
            cnt[i] += deltaCount;
            sum[i] += deltaSum;
        }
    }

    ll sumKSmallest(int k) const {
        int idx = 0;
        int got = 0;
        ll acc = 0;
        for (int step = bitMask; step > 0; step >>= 1) {
            int nxt = idx + step;
            if (nxt <= n && got + cnt[nxt] < k) {
                idx = nxt;
                got += cnt[nxt];
                acc += sum[nxt];
            }
        }
        int value = idx;
        return acc + 1LL * (k - got) * value;
    }
};

static inline int id2(int i, int j, int W) {
    return i * W + j;
}

static inline bool hasSquareAtLeastK(const vector<int>& pref, int L, int D, int K) {
    int W = L + 1;
    for (int i = D + 1; i <= L; i++) {
        int i0 = i - D - 1;
        for (int j = D + 1; j <= L; j++) {
            int j0 = j - D - 1;
            int cnt = pref[id2(i, j, W)]
                    - pref[id2(i0, j, W)]
                    - pref[id2(i, j0, W)]
                    + pref[id2(i0, j0, W)];
            if (cnt >= K) return true;
        }
    }
    return false;
}

vector<pair<int, int>> solve(int N, int M, int K, vector<string>& g) {
    int L = N + M + 1;
    int W = L + 1;

    vector<vector<Node>> byU(L + 2);
    vector<int> pref(W * W, 0);

    for (int i = 0; i < N; i++) {
        int cntHash = 0;
        for (int j = 0; j < M; j++) if (g[i][j] == '#') cntHash++;

        int leftHash = 0;
        for (int j = 0; j < M; j++) {
            if (g[i][j] == '-') {
                int a = min(leftHash, cntHash - leftHash);
                int u = i + j + 1;
                int v = i - j + M;
                if (1 <= u && u <= L && 1 <= v && v <= L) {
                    pref[id2(u, v, W)]++;
                    byU[u].push_back({i, j, a, v});
                }
            } else {
                leftHash++;
            }
        }
    }

    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            pref[id2(i, j, W)] += pref[id2(i - 1, j, W)] + pref[id2(i, j - 1, W)] - pref[id2(i - 1, j - 1, W)];
        }
    }

    int lo = 0, hi = N + M, D = hi;
    while (lo <= hi) {
        int md = (lo + hi) / 2;
        if (hasSquareAtLeastK(pref, L, md, K)) {
            D = md;
            hi = md - 1;
        } else {
            lo = md + 1;
        }
    }

    vector<int> sc(L + 2, 0);
    vector<unordered_map<int, int>> freq(L + 2);

    auto addPoint = [&](const Node& p) {
        sc[p.v]++;
        freq[p.v][p.a]++;
    };
    auto removePoint = [&](const Node& p) {
        sc[p.v]--;
        auto& mp = freq[p.v];
        auto it = mp.find(p.a);
        if (it != mp.end()) {
            if (--it->second == 0) mp.erase(it);
        }
    };

    ll bestCost = (ll)4e18;
    int bestU = -1, bestV = -1;

    int maxA = M;
    Fenwick fw(maxA);

    for (int u0 = 1; u0 <= L - D; u0++) {
        if (u0 == 1) {
            for (int u = 1; u <= 1 + D; u++) {
                for (const auto& p : byU[u]) addPoint(p);
            }
        } else {
            for (const auto& p : byU[u0 - 1]) removePoint(p);
            int uIn = u0 + D;
            if (uIn <= L) {
                for (const auto& p : byU[uIn]) addPoint(p);
            }
        }

        fw.init(maxA);
        int totalInVWindow = 0;

        for (int v = 1; v <= 1 + D; v++) {
            if (sc[v] == 0) continue;
            totalInVWindow += sc[v];
            for (const auto& kv : freq[v]) fw.addVal(kv.first, kv.second);
        }

        for (int v0 = 1; v0 <= L - D; v0++) {
            if (totalInVWindow >= K) {
                ll cur = fw.sumKSmallest(K);
                if (cur < bestCost) {
                    bestCost = cur;
                    bestU = u0;
                    bestV = v0;
                }
            }

            int vOut = v0;
            int vIn = v0 + D + 1;
            if (vIn <= L) {
                if (sc[vOut] != 0) {
                    totalInVWindow -= sc[vOut];
                    for (const auto& kv : freq[vOut]) fw.addVal(kv.first, -kv.second);
                }
                if (sc[vIn] != 0) {
                    totalInVWindow += sc[vIn];
                    for (const auto& kv : freq[vIn]) fw.addVal(kv.first, kv.second);
                }
            }
        }
    }

    vector<Node> cand;
    for (int u = bestU; u <= bestU + D; u++) {
        for (const auto& p : byU[u]) {
            if (bestV <= p.v && p.v <= bestV + D) cand.push_back(p);
        }
    }

    sort(cand.begin(), cand.end(), [](const Node& x, const Node& y) {
        if (x.a != y.a) return x.a < y.a;
        if (x.r != y.r) return x.r < y.r;
        return x.c < y.c;
    });

    vector<pair<int, int>> res;
    for (int i = 0; i < K; i++) res.push_back({cand[i].r, cand[i].c});
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        vector<string> GRID(M);
        for (int i = 0; i < M; i++) cin >> GRID[i];

        auto result = solve(M, N, K, GRID);
        for (auto& p : result) cout << p.first << " " << p.second << "\n";
    }
    return 0;
}