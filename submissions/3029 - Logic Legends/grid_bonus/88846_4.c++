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

        // DP:
        // minimize sum |b[i]-b[i+1]| + sum |b[i]-A[i]|
        // correct heap-based slope trick
        priority_queue<ll> left_heap;
        priority_queue<ll, vector<ll>, greater<ll>> right_heap;

        vector<ll> low(N), high(N);

        for (int i = 0; i < N; i++) {
            ll x = A[i];

            left_heap.push(x);
            right_heap.push(x);

            if (left_heap.top() > right_heap.top()) {
                ll l = left_heap.top(); left_heap.pop();
                ll r = right_heap.top(); right_heap.pop();
                left_heap.push(r);
                right_heap.push(l);
            }

            low[i] = left_heap.top();
            high[i] = right_heap.top();
        }

        vector<ll> the_two_tower_heights(N);

        the_two_tower_heights[N - 1] =
            max(low[N - 1], min(high[N - 1], A[N - 1]));

        for (int i = N - 2; i >= 0; i--) {
            the_two_tower_heights[i] =
                max(low[i], min(high[i], the_two_tower_heights[i + 1]));
        }

        for (int i = 0; i < N; i++) {
            if (i) cout << ' ';
            cout << the_two_tower_heights[i];
        }
        cout << '\n';
    }

    return 0;
}