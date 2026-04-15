#include <bits/stdc++.h>
using namespace std;

#define ll long long

string a, b;

void solve()
{
    cin >> a >> b;
    ll bidx=0;
    for (int i=0; i<a.length(); i++)
    {
        if (bidx==b.length() || a[i]!=b[bidx])
        {
            a[i]='#';
        } 
        else
        {
            bidx++;
        }
    }
    cout << a << "\n";
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