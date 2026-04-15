#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        
        unsigned long long ans = 0;
        
        vector<int> nums(N);
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
            if (i > 0) {
                ans += abs(nums[i] - nums[i-1]);
            }
        }
        sort(nums.begin(), nums.end());
        
        if (N % 2 == 1) {
            int best = nums[N / 2];
            for (int val : nums) {
                ans += abs(val - best);
            }
            cout << ans << '\n';
        }
        else
        {
            int best1 = (nums[N / 2] + nums[N / 2 - 1]) / 2;
            int best2 = (nums[N / 2] + nums[N / 2 - 1]) / 2 + 1;
            unsigned long long ans1 = 0;
            unsigned long long ans2 = 0;
            for (int val : nums) {
                ans1 += abs(val - best1);
                ans2 += abs(val - best2);
            }
            cout << ans + min(ans1,ans2) << '\n';
        }
    }
    
    return 0;
}