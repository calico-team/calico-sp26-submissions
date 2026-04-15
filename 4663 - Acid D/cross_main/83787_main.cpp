#include <iostream>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    for(int ii=0; ii<t; ii++)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << (i+2*j)%5 << " ";
            }
            cout << '\n';
        }
    }
}
