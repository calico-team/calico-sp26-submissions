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
    long long n, p, r, k;
    cin >> n >> p >> r >> k;

    vector <long long> a(n);
    for(long long &it : a)
    {
        cin >> it;
    }

    for(int i = 0 ; i < n ; ++i)
    {
        p -= a[i];
        if(p < 0)
        {
            cout << "nah i'd lose" << endl;
            return;
        }
        if((i + 1) % k == 0)
        {
            p += r;
        }
        
    }

    cout << "nah i'd win" << endl;
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