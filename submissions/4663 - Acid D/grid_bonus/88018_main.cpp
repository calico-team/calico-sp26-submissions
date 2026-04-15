#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    for(int ii=0; ii<t; ii++)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        cout << a[0] << " ";
        int pr=a[0];
        for(int i=1; i<n-1; i++)
        {
            vector<int>v= {pr,a[i],a[i+1]};
            sort(v.begin(),v.end());
            cout << v[1] << " ";
            pr=v[1];
        }
        cout << a[n-1] << '\n';
    }
}
