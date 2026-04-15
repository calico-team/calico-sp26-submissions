#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int N, P, R, K;
	for (int i = 0; i < n; i++)
	{
		cin >> N >> P >> R >> K;
		int E [N];
		int sum = 0;
		
		for (int j = 0; j < N; j++)
		{
			cin >> E [i];
			sum += E [i]; 
		}
		if (sum >= P)
		{
			cout << "nah i��d lose\n";
		}
		else
		{
			cout << "nah i��d win\n";
		}
	}
	return 0;
}
