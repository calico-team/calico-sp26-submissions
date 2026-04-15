#include <bits/stdc++.h>
using namespace std;

int piezoelectric (int l, int w, int e, int r)
{
	int Re = e / ((l + w) * 2 * r);
	return Re;
}

int main()
{
	int n;
	cin >> n;
	
	int L, W, E, R;
	for (int i = 0; i < n; i++)
	{
		cin >> L >> W >> E >> R;
		cout << piezoelectric(L, W, E, R) << endl;
	}
	return 0;
}
