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
		string s1, s2; cin >> s1 >> s2;
		string result = "";
		int idx = 0;
		for (int i = 0; i < s1.size(); i++)
		{
			if (idx < s2.size() && s1[i] == s2[idx])
			{
				result += s1[i]; idx++;
			}
			else result += '#';
		}
		cout << result << endl;
	}
	return 0;
}