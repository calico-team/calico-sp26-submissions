#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MAXN=1e4+5;

ll n, p, r, k, e[MAXN];
bool works;

void solve()
{
    cin >> n >> p >> r >> k;
    works=1;
    for (int i=0; i<n; i++)
    {
        cin >> e[i];
        if (i>0 && i%k==0)
        {
            p+=r;
        }
        p-=e[i];
        if (p<0)
        {
            works=0;
        }
    }
    cout << "nah i'd " << (works ? "win":"lose") << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}