#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Block {
    priority_queue<ll> L;
    priority_queue<ll, vector<ll>, greater<ll>> R;

    void push(ll x) {
        if (L.empty() || x <= L.top()) L.push(x);
        else R.push(x);

        // 平衡
        if (L.size() > R.size() + 1) {
            R.push(L.top()); L.pop();
        } else if (R.size() > L.size()) {
            L.push(R.top()); R.pop();
        }
    }

    ll median() {
        return L.top();
    }

    void merge(Block &other) {
        // 小并大
        if (other.L.size() + other.R.size() > L.size() + R.size()) {
            swap(*this, other);
        }

        while (!other.L.empty()) {
            push(other.L.top());
            other.L.pop();
        }
        while (!other.R.empty()) {
            push(other.R.top());
            other.R.pop();
        }
    }
};

vector<ll> solve(vector<ll> A) {
    vector<Block> stk;

    for (ll x : A) {
        Block cur;
        cur.push(x);
        stk.push_back(move(cur));

        while (stk.size() >= 2) {
            auto &b = stk.back();
            auto &a = stk[stk.size() - 2];

            if (a.median() <= b.median()) break;

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
        int sz = blk.L.size() + blk.R.size();
        for (int i = 0; i < sz; i++) {
            res.push_back(m);
        }
    }
    return res;
}

ll cost(vector<ll>& A, vector<ll>& b) {
    ll s = 0;
    int n = A.size();
    for (int i = 0; i < n - 1; i++) s += abs(b[i] - b[i+1]);
    for (int i = 0; i < n; i++) s += abs(A[i] - b[i]);
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

        auto b1 = solve(A);

        reverse(A.begin(), A.end());
        auto b2 = solve(A);
        reverse(b2.begin(), b2.end());
        reverse(A.begin(), A.end());

        if (cost(A, b1) <= cost(A, b2)) {
            for (auto x : b1) cout << x << " ";
        } else {
            for (auto x : b2) cout << x << " ";
        }
        cout << "\n";
    }
}