#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Block {
    priority_queue<ll> L; // max heap
    priority_queue<ll, vector<ll>, greater<ll>> R; // min heap

    void add(ll x) {
        if (L.empty() || x <= L.top()) L.push(x);
        else R.push(x);

        // balance
        if (L.size() > R.size() + 1) {
            R.push(L.top()); L.pop();
        } else if (R.size() > L.size()) {
            L.push(R.top()); R.pop();
        }
    }

    ll median() const {
        return L.top();
    }

    int size() const {
        return L.size() + R.size();
    }

    // merge small into big（关键优化）
    void merge(Block &other) {
        if (other.size() > size()) swap(*this, other);

        while (!other.L.empty()) {
            add(other.L.top());
            other.L.pop();
        }
        while (!other.R.empty()) {
            add(other.R.top());
            other.R.pop();
        }
    }
};

vector<ll> solve_isotonic(vector<ll> A) {
    vector<Block> stk;

    for (ll x : A) {
        Block cur;
        cur.add(x);
        stk.push_back(move(cur));

        while (stk.size() >= 2) {
            auto &b = stk.back();
            auto &a = stk[stk.size() - 2];

            if (a.median() <= b.median()) break;

            // merge
            Block merged;
            merged.merge(a);
            merged.merge(b);

            stk.pop_back();
            stk.pop_back();
            stk.push_back(move(merged));
        }
    }

    vector<ll> res;
    for (auto &blk : stk) {
        ll m = blk.median();
        int sz = blk.size();
        for (int i = 0; i < sz; i++) {
            res.push_back(m);
        }
    }
    return res;
}

ll calc_cost(const vector<ll>& A, const vector<ll>& b) {
    int n = A.size();
    ll s = 0;
    for (int i = 0; i < n - 1; i++) {
        s += abs(b[i] - b[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        s += abs(A[i] - b[i]);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<ll> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        // 非降
        vector<ll> b1 = solve_isotonic(A);

        // 非升
        vector<ll> revA = A;
        reverse(revA.begin(), revA.end());
        vector<ll> b2 = solve_isotonic(revA);
        reverse(b2.begin(), b2.end());

        if (calc_cost(A, b1) <= calc_cost(A, b2)) {
            for (auto x : b1) cout << x << " ";
        } else {
            for (auto x : b2) cout << x << " ";
        }
        cout << "\n";
    }
}