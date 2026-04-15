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
        for (int& i : nums) {
            cin >> i;
        }
        
        sort(nums.begin(), nums.end());
        cout << nums[1] << ' ' << nums[1] << ' ' << nums[1] << '\n';
        continue;
    }
    
    return 0;
}