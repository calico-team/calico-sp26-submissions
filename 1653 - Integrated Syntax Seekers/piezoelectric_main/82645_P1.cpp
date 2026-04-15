// problem: https://calicojudge.com/team/problems/859/statement
// time complexity: O(1);
// i/o: stdio 
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
        int l, w, e, r; cin >> l >> w >> e >> r;

        // algo
        int x = e/((2*l + 2*w) * r);

        // output
        cout << x << '\n';
    }

    return 0;
}
