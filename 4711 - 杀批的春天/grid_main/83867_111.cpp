#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--)
	{
		int n, result = 0; cin >> n;
		vector<int> nums(n), results(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i]; if (i > 0) result += abs(nums[i] - nums[i-1]);
		}
		vector<int> nums2 = nums;
		sort(nums2.begin(),nums2.end());
		int idx = -1, temp = result;
		result *= 2;
		for (int i = 1; i < n; i++) temp += abs(nums2[i] - nums2[0]);
		if (temp < result)
		{
			result = temp; idx = 0;
		}
		for (int i = 1; i < n; i++)
		{
			temp += (nums2[i] - nums2[i-1]) * i;
			temp -= (nums2[i] - nums2[i-1]) * (n - i);
			if (temp < result)
			{
				result = temp; idx = i;
			}
		}
		if (idx == -1)
		{
			for (int i = 0; i < n; i++)
			{
				cout << nums[i];
				if (i < n - 1) cout << " ";
			}
			cout << endl;
		}else
		{
			for (int i = 0; i < n; i++)
			{
				cout << nums2[idx]; if (i < n - 1) cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}