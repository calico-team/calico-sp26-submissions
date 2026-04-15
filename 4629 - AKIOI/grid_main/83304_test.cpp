#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n;
int a[N], b[N];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        cout << a[1] << ' ';
        for (int i = 3; i <= n; i++)
        {
            if (a[i] > a[i - 1])
                cout << (b[i - 1] = a[i - 1]) << ' ';
            else if (a[i] < b[i - 2])
                cout << (b[i - 1] = b[i - 2]) << ' ';
            else
                cout << (b[i - 1] = a[i]) << ' ';
        }
        cout << a[n] << endl;
    }

    return 0;
}
/*
1
4
1 2 3 4
*/