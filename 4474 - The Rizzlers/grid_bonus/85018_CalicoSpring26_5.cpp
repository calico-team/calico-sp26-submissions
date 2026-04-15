#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;

int main() {
    FASTIO;
    ll t, n;
    cin >> t;
    vector<ll> nums, tosort;
    while (t--)
    {
        cin >> n;
        nums.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        for (int i = 1; i < n - 1; i++)
        {
            tosort.clear();
            tosort.emplace_back(nums[i]);
            tosort.emplace_back(nums[i - 1]);
            tosort.emplace_back(nums[i + 1]);
            sort(tosort.begin(), tosort.end());
            nums[i] = tosort[1];
        }

        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << "\n";

    }

    return 0;
}

