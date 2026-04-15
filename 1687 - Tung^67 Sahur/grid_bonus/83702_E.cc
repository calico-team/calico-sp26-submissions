#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    if (n <= 3) {
        sort(nums.begin(), nums.end());
        int med = nums[n / 2];
        for (int i = 0; i < n; i++) {
            cout << med << " ";
        }
        cout << "\n";
        return;
    }
    // ll prev = 0, curr = 0;
    // vector<pll> dp(n);
    // for (int i = 1; i < n; i++) {
    //     dp[i].second = min(abs(nums[i] - nums[i - 1]) + dp[i - 1].second, abs(nums[i] - nums[i - 2]) + dp[i - 1].first);
    //     dp[i].first = min(abs(nums[i] - nums[i - 1]) + dp[i - 1].first, abs(nums[i] - nums[i - 1]) + dp[i - 1].second);
    // }
    // bool used = dp[n - 1].second >= dp[n - 1].first;
    // vector<int> ans(n);
    // for (int i = n - 1; i >= 0; i--) {
    //     if (used) {
    //         dp[i] = 
    //     }
    // }
    vector<int> ans(n);
    ans[0] = nums[1];
    ans[n - 1] = nums[n - 2];
    for (int i = 1; i < n - 1; i++) {
        int l = min(nums[i - 1], nums[i + 1]);
        int r = max(nums[i - 1], nums[i + 1]);
        if (l <= nums[i] && nums[i] <= r) {
            ans[i] = nums[i];
        } else if (r <= nums[i]) {
            ans[i] = r;
        } else {
            ans[i] = l;
        }
    }
    for (int x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}