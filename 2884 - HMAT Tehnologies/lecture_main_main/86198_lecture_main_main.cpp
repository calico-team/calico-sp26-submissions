#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back

struct Seat
{
    int r, c;
    int u, v;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M, K;
        cin >> N >> M >> K;

        vector<string> g(N);
        rep(i, N)
        {
            cin >> g[i];
        }

        int S = N + M - 1;
        int W = S + 1;

        vector<Seat> seats;
        seats.reserve(N * M);

        rep(r, N)
        {
            rep(c, M)
            {
                if (g[r][c] == '-')
                {
                    Seat s;
                    s.r = r;
                    s.c = c;
                    s.u = r + c;
                    s.v = r - c + (M - 1);
                    seats.pb(s);
                }
            }
        }

        vector<int> pref((S + 1) * (S + 1), 0);
        for (auto &s : seats)
        {
            pref[(s.u + 1) * W + (s.v + 1)]++;
        }

        for (int i = 1; i <= S; i++)
        {
            int bi = i * W;
            int bpm1 = (i - 1) * W;
            for (int j = 1; j <= S; j++)
            {
                pref[bi + j] += pref[bpm1 + j] + pref[bi + (j - 1)] - pref[bpm1 + (j - 1)];
            }
        }

        auto rectSum = [&](int u0, int v0, int u1, int v1)
        {
            if (u0 > u1 || v0 > v1)
            {
                return 0;
            }
            int A = (u1 + 1) * W + (v1 + 1);
            int B = u0 * W + (v1 + 1);
            int C = (u1 + 1) * W + v0;
            int D = u0 * W + v0;
            return pref[A] - pref[B] - pref[C] + pref[D];
        };

        auto can = [&](int d, int &bestU, int &bestV)
        {
            vector<int> hi(S);
            rep(i, S)
            {
                int x = i + d;
                if (x >= S)
                {
                    x = S - 1;
                }
                hi[i] = x;
            }

            rep(u0, S)
            {
                int u1 = hi[u0];
                rep(v0, S)
                {
                    int v1 = hi[v0];
                    if (rectSum(u0, v0, u1, v1) >= K)
                    {
                        bestU = u0;
                        bestV = v0;
                        return true;
                    }
                }
            }
            return false;
        };

        int lo = 0, hi = S - 1;
        int tmpU = 0, tmpV = 0;
        while (lo < hi)
        {
            int mid = (lo + hi) >> 1;
            if (can(mid, tmpU, tmpV))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        int bestD = lo;
        int u0 = 0, v0 = 0;
        can(bestD, u0, v0);
        int u1 = min(S - 1, u0 + bestD);
        int v1 = min(S - 1, v0 + bestD);

        vector<pair<int, int>> ans;
        ans.reserve(K);
        for (auto &s : seats)
        {
            if (s.u >= u0 && s.u <= u1 && s.v >= v0 && s.v <= v1)
            {
                ans.pb({s.r, s.c});
                if ((int)ans.size() == K)
                {
                    break;
                }
            }
        }

        rep(i, K)
        {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }

    return 0;
}
