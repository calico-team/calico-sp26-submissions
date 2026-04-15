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
        
        if (N == 1) {
            int v1;
            cin >> v1;
            cout << v1 << '\n';
            continue;
        }
        if (N == 2) {
            int v1,v2;
            cin >> v1; cin >> v2;
            cout << v1 << ' ' << v2 << ' ' << '\n';
            continue;
        }
        
        vector<int> nums(N);
        unsigned long long ans = 0;
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
            if (i > 0) {
                ans += abs(nums[i] - nums[i-1]);
            }
        }
        sort(nums.begin(), nums.end());
        cout << min(nums[0], nums[1]) << ' ' << nums[1] << ' ' << min(nums[1], nums[2]) << '\n';
        continue;
    }
    
    return 0;
}