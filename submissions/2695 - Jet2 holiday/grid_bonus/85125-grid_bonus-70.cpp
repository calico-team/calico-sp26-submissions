#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 计算总代价
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


vector<ll> isotonic(vector<ll> A) {
    int n = A.size();


    vector<vector<ll>> blocks;

    for (int i = 0; i < n; i++) {
        blocks.push_back({A[i]});


        while (blocks.size() >= 2) {
            auto& B = blocks.back();
            auto& C = blocks[blocks.size() - 2];


            auto get_med = [](vector<ll>& v) {
                vector<ll> tmp = v;
                nth_element(tmp.begin(), tmp.begin() + tmp.size()/2, tmp.end());
                return tmp[tmp.size()/2];
            };

            ll medB = get_med(B);
            ll medC = get_med(C);

            if (medC <= medB) break;


            vector<ll> merged;
            merged.reserve(B.size() + C.size());
            merged.insert(merged.end(), C.begin(), C.end());
            merged.insert(merged.end(), B.begin(), B.end());

            blocks.pop_back();
            blocks.pop_back();
            blocks.push_back(merged);
        }
    }


    vector<ll> res;
    for (auto& blk : blocks) {
        vector<ll> tmp = blk;
        nth_element(tmp.begin(), tmp.begin() + tmp.size()/2, tmp.end());
        ll med = tmp[tmp.size()/2];

        for (int i = 0; i < (int)blk.size(); i++) {
            res.push_back(med);
        }
    }

    return res;
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
        vector<ll> b1 = isotonic(A);

        // 非升（反转）
        vector<ll> revA = A;
        reverse(revA.begin(), revA.end());

        vector<ll> b2 = isotonic(revA);
        reverse(b2.begin(), b2.end());

        // 选更优
        if (calc_cost(A, b1) <= calc_cost(A, b2)) {
            for (auto x : b1) cout << x << " ";
        } else {
            for (auto x : b2) cout << x << " ";
        }
        cout << "\n";
    }
}