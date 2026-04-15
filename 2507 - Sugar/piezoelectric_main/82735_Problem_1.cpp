#include <bits/stdc++.h>
using namespace std;

int l[15], w[15], e[15], r[15];

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> l[i] >> w[i] >> e[i] >> r[i];
        int parameter = (l[i] + w[i]) * 2;
        cout << (e[i] / r[i]) / parameter << endl;
    }
    return 0;
}