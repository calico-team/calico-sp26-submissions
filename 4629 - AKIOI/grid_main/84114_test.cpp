#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, mini, maxi;
int a[N], b1[N];
int a2[N], b2[N];

// void dfs(int now)
// {
//     if (now > n)
//     {
//     }
//     for (int i = mini; i <= maxi; i++)
//     {
//         b[i]=
//     }
// }

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        mini = 0x7fffffff, maxi = -mini;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a2[n - i + 1] = a[i];
            mini = min(mini, a[i]), maxi = max(maxi, a[i]);
        }

        b1[1] = a[1];
        for (int i = 3; i <= n; i++)
        {
            if (a[i] > a[i - 1])
                b1[i - 1] = a[i - 1];
            else if (a[i] < b1[i - 2])
                b1[i - 1] = b1[i - 2];
            else
                b1[i - 1] = a[i];
        }
        b1[n] = a[n];

        b2[1] = a2[1];
        for (int i = 3; i <= n; i++)
        {
            if (a2[i] > a2[i - 1])
                b2[i - 1] = a2[i - 1];
            else if (a2[i] < b2[i - 2])
                b2[i - 1] = b2[i - 2];
            else
                b2[i - 1] = a2[i];
        }
        b2[n] = a2[n];

        mini = maxi = 0;
        for (int i = 1; i < n; i++)
        {
            mini += abs(a[i] - b1[i]) + abs(b1[i] - b1[i + 1]);
            maxi += abs(a2[i] - b2[i]) + abs(b2[i] - b2[i + 1]);
        }
        if (mini + abs(a[n] - b1[n]) < maxi + abs(a2[n] - b2[n]))
            for (int i = 1; i <= n; i++)
                cout << b1[i] << ' ';
        // cout << endl;
        else
            for (int i = n; i >= 1; i--)
                cout << b2[i] << ' ';
        cout << endl;
        // cout << mini + abs(a[n] - b1[n]) << ' ' << maxi + abs(a2[n] - b2[n]) << endl;
    }

    return 0;
}
/*
1
4
1 2 3 4
*/