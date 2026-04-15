#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
string solve(int N, vector<string> S1, vector<string> S2) {
    // YOUR CODE HERE
    ll max_vol = 0;
    for (int x = 0;x < N; x++)
	{
        for (int z = 0;z < N; z++)
		{
            if (S1[x][z] == '#')
			{
                bool ok = false;
                for (int y = 0; y < N; y++)
				{
                    if (S2[y][z] == '#')
					{
                        ok = true;
                        break;
                    }
                }
                if (ok) max_vol++;
            }
        }
    }

    ll cnt1 = 0;
    for (int x = 0; x < N; x++)
	{
        for (int z = 0; z < N; z++)
		{
            if (S1[x][z] == '#') cnt1++;
        }
    }

    int cnt2 = 0;
    for(int z = 0; z < N; z++)
	{
        bool f = false;
        for (int y = 0; y < N; y++)
		{
            if(S2[y][z] == '#')
			{
                f = true;
                break;
            }
        }
        if(f) cnt2++;
    }

    ll min_vol = max(cnt1, (ll)cnt2);
    return to_string(max_vol) + " " + to_string(min_vol);
    return "-1 -1";
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<string> S1(N);
        for (int i = 0; i < N; i++) {
            cin >> S1[i];
        }
        vector<string> S2(N);
        for (int i = 0; i < N; i++) {
            cin >> S2[i];
        }
        cout << solve(N, S1, S2) << '\n';
    }
}
