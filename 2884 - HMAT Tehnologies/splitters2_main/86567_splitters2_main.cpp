#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        long long P;
        int A, B;
        cin >> P >> A >> B;

        vector<int> base;
        base.reserve(A + B);
        rep(i, A) base.push_back(2);
        rep(i, B) base.push_back(3);

        int n = (int)base.size();
        vector<int> dig(n, 0);

        long long cur = P;
        for (int i = n - 1; i >= 0; i--)
        {
            dig[i] = (int)(cur % base[i]);
            cur /= base[i];
        }

        int N = 5;
        int M = 3 * n + 2;
        vector<string> g(N, string(M, 'X'));

        g[0][0] = 'v';
        g[1][0] = 'v';
        g[2][0] = '>';
        g[2][1] = '>';

        rep(i, n)
        {
            int c = 2 + 3 * i;
            int k = base[i];
            int d = dig[i];

            g[2][c] = 'S';
            g[2][c - 1] = '>';

            if (i + 1 < n)
            {
                g[2][c + 1] = '>';
                g[2][c + 2] = '>';
            }
            else
            {
                // Final stage keeps one non-collected branch that is destroyed.
                g[2][c + 1] = 'X';
            }

            if (k == 2)
            {
                // Two-way split: right + up.
                if (d == 1)
                {
                    g[1][c] = '^';
                    g[0][c] = '^';
                }
                else
                {
                    g[1][c] = 'X';
                    g[0][c] = 'X';
                }

                // Make down invalid for this splitter.
                g[3][c] = '^';
            }
            else
            {
                // Three-way split: right + up + down.
                if (d >= 1)
                {
                    g[1][c] = '^';
                    g[0][c] = '^';
                }
                else
                {
                    g[1][c] = 'X';
                    g[0][c] = 'X';
                }

                if (d == 2)
                {
                    g[3][c] = 'v';
                    g[4][c] = 'v';
                }
                else
                {
                    g[3][c] = 'X';
                    g[4][c] = 'X';
                }
            }
        }

        cout << N << ' ' << M << '\n';
        rep(r, N)
        {
            cout << g[r] << '\n';
        }
    }

    return 0;
}
