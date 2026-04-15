#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int K, N, M, P, Q;
	for (int i = 0; i < n; i++)
	{
		cin >> K >> N >> M >> P >> Q;
		
		int sum = 0;
		int a = 0;
		for (int j = 0; j < K; j++) 
		{
			cin >> a;
			sum += a;
		}
		int all = N + M + P + Q;
		if ((abs(sum - all) - 1) > 0)
			cout << abs(sum - all) - 1;
		else
			cout << 0;
	}
	return 0;
}
