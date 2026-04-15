#include <bits/stdc++.h>
using namespace std;
#define int long long

int calc(const vector<int>& arr, int val) {
    int res = 0;
    for (int i : arr) {
        res += abs(val - i);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int& i : arr) {
            cin >> i;
        }
        int low = 1;
        int high = 2'000'000'000;
        while (high - low >= 3) {
            int m1 = low + (high - low) / 3;
            int m2 = high - (high - low) / 3;
            if (calc(arr, m1) < calc(arr, m2)) {
                high = m2 - 1;
            }
            else {
                low = m1 + 1;
            }
        }
        int res = low;
        int sum = calc(arr, low);
        for (int i = low + 1; i <= high; ++i) {
            if (calc(arr, i) < sum) {
                res = i;
                sum = calc(arr, i);
            }
        }
        for (int i = 0; i < N; ++i) {
            cout << res << ' ';
        }
        cout << '\n';
    }
}