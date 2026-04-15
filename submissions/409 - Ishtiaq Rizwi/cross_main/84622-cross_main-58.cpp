#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree <int, null_type,less <int>, rb_tree_tag, tree_order_statistics_node_update>
#define MyFast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector <vector <int>> g(n, vector <int>(m));
    
    for(int j = 0 ; j < n ; ++j)
    {
        int x = (3 * j) % 5;
        for(int i = 0 ; i < m ; ++i)
        {
            g[j][i] = x;
            x = (x + 1) % 5;
        }
    }
    
    for(auto &x : g)
    {
        for(int &it : x)
        {
            cout << it << ' ';
        }
        cout << endl;
    }
}

int main()
{
    MyFast;
    int t = 1;
    cin >> t;

    while(t--)
    {
        solve();
    }
    return 0;
}