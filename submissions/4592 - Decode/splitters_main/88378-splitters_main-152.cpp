#include <bits/stdc++.h>
using namespace std;


void simplify(pair<long long, long long> & to)
{
	int common = gcd(to.first, to.second);
	to = {to.first / common, to.second / common};
}

void add(pair<long long, long long> & to, pair<long long, long long> by)
{
	to = {to.first * by.second + to.second * by.first, to.second * by.second};
	simplify(to);
}

void testcase()
{
	queue<pair<pair<long long, long long>, pair<long long, long long>>> q;
	long long n, m;
	cin >> n >> m;

	vector<string> factory;

	for(long long i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		factory.push_back(s);
	}

	
	q.push({{0, 0}, {1, 1}});

	pair<long long, long long> total = {0, 1};

	while(!q.empty())
	{
		pair<long long, long long> coord = q.front().first;
		pair<long long, long long> fract = q.front().second;
		q.pop();

		long long x = coord.first;
		long long y = coord.second;

		//cout << "DBG1\n";

		if(x < 0 || x >= n || y < 0 || y >= m)
		{

			//cout << "Reached End, ADDING " << fract.first << '/' << fract.second << " at " << x << ' ' << y << '\n';
			add(total, fract);
			continue;
		}

		//cout << "AT: " << x << ' ' << y << " w/ " << factory[x][y] <<'\n';
		assert(factory[x][y] != '.');

		switch(factory[x][y])
		{
			case '<':
				q.push({{x, y-1}, fract});
				break;
			case '>':
				q.push({{x, y+1}, fract});
				break;
			case '^':
				q.push({{x-1, y}, fract});
				break;
			case 'v':
				q.push({{x+1, y}, fract});
				break;
			case 'S':
				{
					vector<pair<long long, long long>> tosplit;

					if(factory[x+1][y] == 'X' || factory[x+1][y] == 'v') tosplit.push_back({x+1, y});
					if(factory[x-1][y] == 'X' || factory[x-1][y] == '^') tosplit.push_back({x-1, y});
					if(factory[x][y+1] == 'X' || factory[x][y+1] == '>') tosplit.push_back({x, y+1});
					if(factory[x][y-1] == 'X' || factory[x][y-1] == '<') tosplit.push_back({x, y-1});

					for(pair<long long, long long> p : tosplit)
					{
						q.push({p, {fract.first, fract.second * tosplit.size()}});
					}
				}
				break;
			case 'X':
				break;
		}
	}

	cout << total.first << ' ' << total.second << '\n'; // fraction {num, denom}
}

int main()
{
	int T;
	cin >> T;
	while(T--) testcase();
	return 0;
}
