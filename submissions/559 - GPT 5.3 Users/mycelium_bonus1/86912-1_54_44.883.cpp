#include <bits/stdc++.h>

using namespace std;
#define V vector

using pii = pair<int, int>;

#define F first
#define S second
#define PB push_back
#define read(arr) for (auto &x : arr) cin >> x
#define show(arr) for (auto x : arr) cout << x << " "; cout << endl
#define FOR(v,l,h) for (int v = l; v < h; v ++)

const char G = 1, M = 2, A = 4;
int dx[4] {1, -1, 0, 0}, dy[4] {0, 0, 1, -1};
const int SZ = 4000;
unsigned char board[SZ][SZ];

signed main()
{
    int tst;
    cin >> tst;
    while (tst --)
    {
        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;

        for (int i = 0; i < SZ; i ++)
            for (int j = 0; j < SZ; j ++)
            {
                board[i][j] = 0;
            }
        xg += SZ / 2;
        yg += SZ / 2;
        xm += SZ / 2;
        ym += SZ / 2;

        board[xg][yg] = G | A;
        board[xm][ym] = M | A;

        V<pii> outg, outm;
        outm.push_back({xm,ym});
        outg.push_back({xg,yg});
        int g = 1, m = 1, ag = 1, am = 1;
        int t = 0;
        while (am)
        {
            t ++;
            if (t % 7 == 0)
            {
                V<pii> noutm;
                for (auto [x, y] : outm)
                {
                    assert(board[x][y] == (M | A) || (board[x][y] & G));
                    if (board[x][y] != (M | A)) continue;
                    for (int i = 0; i < 4; i ++)
                    {
                        int nx = x + dx[i], ny = y + dy[i];
                        if (board[nx][ny] & G || board[nx][ny] & M) continue;
                        board[nx][ny] = M | A;
                        noutm.push_back({nx, ny});
                        m ++, am ++;
                    }
                    am --;
                    board[x][y] = M;
                }
                outm = noutm;
            }
            if (t % 2 == 0)
            {
                V<pii> noutg;
                for (auto [x, y] : outg)
                {
                    // printf("got %d for %lld %lld\n", board[x][y], x, y);
                    assert(board[x][y] == (G | A));
                    for (int i = 0; i < 4; i ++)
                    {
                        int nx = x + dx[i], ny = y + dy[i];
                        // printf("got %d for %lld %lld\n", board[nx][ny], nx, ny);
                        if (board[nx][ny] & G) continue;
                        if (board[nx][ny] == M) continue;
                        if (board[nx][ny] == (M | A))
                        {
                            if (t % 7 == 0)
                            {
                                m --, am --, g ++, ag ++;
                                noutg.push_back({nx, ny});
                            } else continue;
                        }
                        else
                        {
                            assert(board[nx][ny] == 0);
                            noutg.push_back({nx, ny});
                            g ++, ag ++;
                        }
                        board[nx][ny] = G | A;
                    }
                    ag --;
                    board[x][y] = G;
                }
                outg = noutg;
            }
        }
        cout << m << endl;
    }
}
