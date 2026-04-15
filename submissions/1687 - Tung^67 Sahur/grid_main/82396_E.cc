#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    sort(nums.begin(), nums.end());
    int med = nums[n / 2];
    for (int i = 0; i < n; i++) {
        cout << med << " ";
    }
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