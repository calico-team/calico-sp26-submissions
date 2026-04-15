// problem: https://calicojudge.com/team/problems/867/statement
// time complexity:
// i/o: 
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
template<typename T>
using v = vector<T>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--)
    {
        // input
        int m, n; cin >> m >> n;

        // algo + output
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int val = ( (i % 5) + (2 * (j % 5)) ) % 5;
                cout << val;
                if(j + 1 < n) cout << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
