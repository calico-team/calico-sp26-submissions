#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        vector<int> results(n);
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n - 1) results[i] = nums[i];
            else
            {
                if (nums[i+1] > max(nums[i], results[i-1])) results[i] = max(nums[i], results[i-1]);
                else results[i] = min(results[i-1], nums[i]);
            }
        }
        for (int i = 0; i < n; i++) cout << results[i] << " ";
        cout << endl;
    }
} 