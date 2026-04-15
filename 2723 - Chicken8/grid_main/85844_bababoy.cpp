#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{

    int dih;
    cin >> dih;
    while (dih--)
    {
        int n;
        cin >> n;
        long long *a = new long long[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        long long *v = new long long[n];
        for (int i = 0; i < n; ++i)
            v[i] = a[i];

        sort(v, v + n);

        int stickm = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i == 0 || v[i] != v[stickm - 1])
                v[stickm++] = v[i];
        }

        const long long inf = 1e18;
        long long *dp = new long long[stickm];
        int **fa = new int *[n];

        for (int i = 0; i < n; ++i)
        {
            fa[i] = new int[stickm];
            for (int j = 0; j < stickm; ++j)
                fa[i][j] = -1;
        }

        for (int j = 0; j < stickm; ++j)
            dp[j] = 0;

        for (int i = 0; i < n; ++i)
        {
            long long *nmsldp = new long long[stickm];
            for (int j = 0; j < stickm; ++j)
                nmsldp[j] = inf;
            for (int j = 0; j < stickm; ++j)
            {
                long long c = abs(a[i] - v[j]);
                if (i == 0)
                {
                    nmsldp[j] = c;
                    fa[i][j] = -1;
                }
                else
                {
                    for (int k = 0; k < stickm; ++k)
                    {
                        long long t = dp[k] + abs(v[j] - v[k]) + c;
                        if (t < nmsldp[j])
                        {
                            nmsldp[j] = t;
                            fa[i][j] = k;
                        }
                    }
                }
            }
            delete[] dp;
            dp = nmsldp;
        }

        int bst = 0;
        for (int j = 1; j < stickm; ++j)
            if (dp[j] < dp[bst])
                bst = j;

        long long *b = new long long[n];
        int cr = bst;
        for (int i = n - 1; i >= 0; --i)
        {
            b[i] = v[cr];
            if (i > 0)
                cr = fa[i][cr];
        }

        for (int i = 0; i < n; ++i)
            cout << b[i] << (i == n - 1 ? "\n" : " ");

        delete[] a;
        delete[] v;
        delete[] dp;
        for (int i = 0; i < n; ++i)
            delete[] fa[i];
        delete[] fa;
        delete[] b;
    }
    return 0;
}