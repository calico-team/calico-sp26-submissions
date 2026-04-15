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
    int n;
    cin >> n;
    
    vector <string> h1(n), h2(n);
    
    for(auto &x : h1)
    {
        cin >> x;
    }
    
    for(auto &x : h2)
    {
        cin >> x;
    }
    
    vector <int> cnt1(n), cnt2(n);
    long long mx = 0, mi = 0;
    
    for(int i = 0 ; i < n ; ++i)
    {
        cnt1[i] = count(h1[i].begin(), h1[i].end(), '#');
        cnt2[i] = count(h2[i].begin(), h2[i].end(), '#');
        mx += (cnt1[i] * cnt2[i]);
        mi += max(cnt1[i], cnt2[i]);
    }
    cout << mx << ' ' << mi << endl;
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