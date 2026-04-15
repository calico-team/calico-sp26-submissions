#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<ll> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];

        vector<ll> left(n + 1), right(n + 1);
        left[1] = right[1] = arr[1];

        for (int i = 2; i <= n; i++) {
            ll vals[4] = {left[i - 1], right[i - 1], arr[i], arr[i]};
            sort(vals, vals + 4);
            left[i] = vals[1];
            right[i] = vals[2];
        }

        vector<ll> res(n + 1);
        res[n] = max(left[n], min(res[n], right[n]));
        
        for (int i = n - 1; i >= 1; i--) arr[i] = max(left[i], min(res[i + 1], right[i]));
        for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    }
}