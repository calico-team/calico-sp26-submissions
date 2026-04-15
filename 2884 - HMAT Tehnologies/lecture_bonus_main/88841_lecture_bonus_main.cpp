#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Seat
{
    int r, c;
    int u, v;
    int aura;
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
        for (int r = 0; r < N; r++)
            cin >> g[r];

        int S = N + M - 1;
        int PW = S + 1;

        vector<Seat> seats;
        seats.reserve(N * M);

        int maxAura = 0;
        for (int r = 0; r < N; r++)
        {
            vector<int> prefOcc(M + 1, 0);
            for (int c = 0; c < M; c++)
                prefOcc[c + 1] = prefOcc[c] + (g[r][c] == '#');
            int totalOcc = prefOcc[M];

            for (int c = 0; c < M; c++)
            {
                if (g[r][c] != '-')
                    continue;

                int leftOcc = prefOcc[c];
                int rightOcc = totalOcc - prefOcc[c + 1];
                int aura = min(leftOcc, rightOcc);
                if (aura > maxAura)
                    maxAura = aura;

                Seat s;
                s.r = r;
                s.c = c;
                s.u = r + c;
                s.v = r - c + (M - 1);
                s.aura = aura;
                seats.push_back(s);
            }
        }

        vector<int> pref(PW * PW, 0);
        for (const auto &s : seats)
        {
            pref[(s.u + 1) * PW + (s.v + 1)]++;
        }

        for (int i = 1; i <= S; i++)
        {
            int bi = i * PW;
            int bp = (i - 1) * PW;
            for (int j = 1; j <= S; j++)
            {
                pref[bi + j] += pref[bp + j] + pref[bi + (j - 1)] - pref[bp + (j - 1)];
            }
        }

        auto rectCnt = [&](int u0, int v0, int u1, int v1)
        {
            int A = (u1 + 1) * PW + (v1 + 1);
            int B = u0 * PW + (v1 + 1);
            int C = (u1 + 1) * PW + v0;
            int D = u0 * PW + v0;
            return pref[A] - pref[B] - pref[C] + pref[D];
        };

        auto feasible = [&](int d)
        {
            int U = S - d;
            for (int u0 = 0; u0 < U; u0++)
            {
                int u1 = u0 + d;
                for (int v0 = 0; v0 < U; v0++)
                {
                    int v1 = v0 + d;
                    if (rectCnt(u0, v0, u1, v1) >= K)
                        return true;
                }
            }
            return false;
        };

        int lo = 0, hi = S - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) >> 1;
            if (feasible(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        int D = lo;

        int U = S - D;
        int V = U;
        int WN = U * V;

        vector<int> total(WN, 0);
        vector<int> viable;
        viable.reserve(WN);
        vector<int> viablePos;
        viablePos.reserve(WN);

        for (int u0 = 0; u0 < U; u0++)
        {
            int u1 = u0 + D;
            for (int v0 = 0; v0 < V; v0++)
            {
                int v1 = v0 + D;
                int win = u0 * V + v0;
                int c = rectCnt(u0, v0, u1, v1);
                total[win] = c;
                if (c >= K)
                {
                    viable.push_back(win);
                    viablePos.push_back(u0 * (V + 1) + v0);
                }
            }
        }

        vector<vector<int>> byAura(maxAura + 1);
        for (int i = 0; i < (int)seats.size(); i++)
        {
            byAura[seats[i].aura].push_back(i);
        }

        vector<int> accCnt(WN, 0);
        vector<long long> accSum(WN, 0);
        vector<unsigned char> done(WN, 0);

        vector<int> diff((U + 1) * (V + 1), 0);

        long long bestCost = LLONG_MAX;
        int bestWin = -1;
        int remain = (int)viable.size();

        for (int w = 0; w <= maxAura && remain > 0; w++)
        {
            if (byAura[w].empty())
                continue;

            fill(diff.begin(), diff.end(), 0);

            for (int idx : byAura[w])
            {
                const auto &s = seats[idx];
                int uL = max(0, s.u - D);
                int uR = min(U - 1, s.u);
                int vL = max(0, s.v - D);
                int vR = min(V - 1, s.v);
                if (uL > uR || vL > vR)
                    continue;

                int p1 = uL * (V + 1) + vL;
                int p2 = (uR + 1) * (V + 1) + vL;
                int p3 = uL * (V + 1) + (vR + 1);
                int p4 = (uR + 1) * (V + 1) + (vR + 1);

                diff[p1]++;
                diff[p2]--;
                diff[p3]--;
                diff[p4]++;
            }

            for (int i = 0; i <= U; i++)
            {
                int base = i * (V + 1);
                for (int j = 1; j <= V; j++)
                    diff[base + j] += diff[base + j - 1];
            }
            for (int i = 1; i <= U; i++)
            {
                int base = i * (V + 1);
                int prev = (i - 1) * (V + 1);
                for (int j = 0; j <= V; j++)
                    diff[base + j] += diff[prev + j];
            }

            for (int z = 0; z < (int)viable.size(); z++)
            {
                int win = viable[z];
                if (done[win])
                    continue;

                int c = diff[viablePos[z]];
                if (c <= 0)
                    continue;

                int prev = accCnt[win];
                int now = prev + c;
                if (now < K)
                {
                    accCnt[win] = now;
                    accSum[win] += 1LL * c * w;
                }
                else
                {
                    int need = K - prev;
                    long long cost = accSum[win] + 1LL * need * w;
                    done[win] = 1;
                    remain--;
                    if (cost < bestCost)
                    {
                        bestCost = cost;
                        bestWin = win;
                    }
                }
            }
        }

        if (bestWin < 0)
        {
            // Fallback to first feasible window (should not happen when constraints are valid).
            for (int win : viable)
            {
                bestWin = win;
                break;
            }
        }

        int bestU0 = bestWin / V;
        int bestV0 = bestWin % V;
        int bestU1 = bestU0 + D;
        int bestV1 = bestV0 + D;

        vector<int> cand;
        cand.reserve(total[bestWin]);
        for (int i = 0; i < (int)seats.size(); i++)
        {
            const auto &s = seats[i];
            if (s.u >= bestU0 && s.u <= bestU1 && s.v >= bestV0 && s.v <= bestV1)
            {
                cand.push_back(i);
            }
        }

        sort(cand.begin(), cand.end(), [&](int a, int b)
             {
            if (seats[a].aura != seats[b].aura) return seats[a].aura < seats[b].aura;
            if (seats[a].r != seats[b].r) return seats[a].r < seats[b].r;
            return seats[a].c < seats[b].c; });

        for (int i = 0; i < K; i++)
        {
            const auto &s = seats[cand[i]];
            cout << s.r << ' ' << s.c << '\n';
        }
    }

    return 0;
}
