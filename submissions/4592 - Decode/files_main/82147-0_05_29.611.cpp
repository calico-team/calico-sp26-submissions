#include <bits/stdc++.h>
using namespace std;

void testcase()
{
	string a, b;
	cin >> a >> b;

	int ptrA = 0;
	int ptrB = 0;

	while(ptrA < a.size())
	{
		if(a[ptrA] == b[ptrB])
		{
			cout << b[ptrB];
			ptrA++; ptrB++;
		}
		else
		{
			cout << '#';
			ptrA++;
		}
	}
	cout << '\n';
}

int main()
{
	int t;
	cin >> t;
	while(t--) testcase();
	return 0;
}
