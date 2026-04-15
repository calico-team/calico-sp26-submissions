#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> solve(vector<ll> a) {
    int n = a.size();
    vector<vector<ll>> st; 

    for (auto num : a) {
        st.push_back({num, 1});

        while (st.size() >= 2) {
            auto& b1 = st[st.size() - 2];
            auto& b2 = st[st.size() - 1];
            if (b2[0] < b1[0]) {
                // 合并两个块
                ll tot = b1[1] + b2[1];
                ll med = (tot % 2 == 1) ? b1[0] : b2[0];
                st.pop_back();
                st.pop_back();
                st.push_back({med, tot});
            } else {
                break;
            }
        }
    }

    vector<ll> b;
    for (auto& p : st) {
        ll val = p[0];
        int cnt = p[1];
        while (cnt--) b.push_back(val);
    }
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        auto res = solve(a);
        for (auto x : res) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}