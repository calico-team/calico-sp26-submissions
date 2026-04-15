#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    int T;
    cin >> T;
    double a, b, c, d;
    while (T--)
    {
        cin >> a >> b >> c >> d;
        cout << ceil(c / (2 * (a + b) * d)) << endl;
    }

    return 0;
}