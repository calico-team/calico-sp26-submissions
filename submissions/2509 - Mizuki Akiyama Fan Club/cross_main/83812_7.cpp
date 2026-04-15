#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int digits[5] = {4, 0, 1, 2, 3};
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << digits[(j + (2 * i)) % 5] << " ";
            }
            cout << "\n";
        }
    }
}