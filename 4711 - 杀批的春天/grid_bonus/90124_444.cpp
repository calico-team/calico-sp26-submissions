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
        ll minNum = 0, temp = 0;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            if (i > 0) minNum += abs(nums[i] - nums[i-1]);
        }
        temp += minNum; minNum *= 2;
        int idx = -1;
        vector<int> num2 = nums;
        sort(num2.begin(),num2.end());
        for (int i = 1; i < n; i++) temp += abs(num2[i] - num2[0]);
        if (temp < minNum)
        {
            minNum = temp; idx = 0;
        }
        for (int i = 1; i < n; i++)
        {
            temp += (num2[i] - num2[i-1]) * i;
            temp -= (num2[i] - num2[i-1]) * (n - i);
            if (temp < minNum)
            {
                minNum = temp; idx = i;
            }
        }
        if (idx == -1)
        {
            for (int i = 0; i < n; i++) cout << nums[i] << " ";
            cout << endl;
        }else
        {
            for (int i = 0; i < n; i++) cout << num2[idx] << " ";
            cout << endl;
        }
    }
} 