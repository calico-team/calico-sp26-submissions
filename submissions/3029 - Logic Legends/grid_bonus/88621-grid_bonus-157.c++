#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<ll> A(N);
        for (auto &x : A) cin >> x;

        // Correct slope trick for:
        // sum |b[i]-b[i+1]| + sum |b[i]-A[i]|
        priority_queue<ll> L; // max heap
        priority_queue<ll, vector<ll>, greater<ll>> R; // min heap

        vector<ll> low(N), high(N);

        for (int i = 0; i < N; i++) {
            ll x = A[i];

            L.push(x);
            R.push(x);

            // maintain max(L) <= min(R)
            if (L.top() > R.top()) {
                ll l = L.top(); L.pop();
                ll r = R.top(); R.pop();
                L.push(r);
                R.push(l);
            }

            low[i] = L.top();
            high[i] = R.top();
        }

        // reconstruct one optimal solution
        vector<ll> the_two_tower_heights(N);

        the_two_tower_heights[N - 1] =
            max(low[N - 1], min(high[N - 1], A[N - 1]));

        for (int i = N - 2; i >= 0; i--) {
            the_two_tower_heights[i] =
                max(low[i], min(high[i], the_two_tower_heights[i + 1]));
        }

        for (int i = 0; i < N; i++) {
            cout << the_two_tower_heights[i];
            if (i + 1 < N) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}