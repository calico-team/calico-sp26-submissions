#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

using i128 = __int128_t;

struct Frac
{
    i128 p, q;
};

static i128 gcd128(i128 a, i128 b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (b != 0)
    {
        i128 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

static Frac norm(Frac f)
{
    if (f.p == 0)
        return {0, 1};
    i128 g = gcd128(f.p, f.q);
    f.p /= g;
    f.q /= g;
    if (f.q < 0)
    {
        f.q = -f.q;
        f.p = -f.p;
    }
    return f;
}

static Frac addFrac(const Frac &a, const Frac &b)
{
    i128 g = gcd128(a.q, b.q);
    i128 l = (a.q / g) * b.q;
    Frac r = {a.p * (l / a.q) + b.p * (l / b.q), l};
    return norm(r);
}

static Frac divInt(const Frac &a, int k)
{
    Frac r = {a.p, a.q * (i128)k};
    return norm(r);
}

static string toString128(i128 x)
{
    if (x == 0)
        return "0";
    bool neg = x < 0;
    if (neg)
        x = -x;
    string s;
    while (x > 0)
    {
        int d = (int)(x % 10);
        s.push_back((char)('0' + d));
        x /= 10;
    }
    if (neg)
        s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    auto step = [&](char ch)
    {
        if (ch == '^')
            return pair<int, int>{-1, 0};
        if (ch == 'v')
            return pair<int, int>{1, 0};
        if (ch == '<')
            return pair<int, int>{0, -1};
        return pair<int, int>{0, 1};
    };

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<string> g(N);
        for (int i = 0; i < N; i++)
            cin >> g[i];

        int V = N * M;
        vector<int> state(V, 0);
        vector<Frac> memo(V, {0, 1});

        auto inside = [&](int r, int c)
        {
            return (r >= 0 && r < N && c >= 0 && c < M);
        };

        auto idOf = [&](int r, int c)
        {
            return r * M + c;
        };

        function<Frac(int, int)> dfs = [&](int r, int c) -> Frac
        {
            int id = idOf(r, c);
            if (state[id] == 2)
                return memo[id];
            if (state[id] == 1)
                return {0, 1};

            state[id] = 1;
            char ch = g[r][c];
            Frac ans = {0, 1};

            if (ch == 'X')
            {
                ans = {0, 1};
            }
            else if (ch == '^' || ch == 'v' || ch == '<' || ch == '>')
            {
                auto [rr, cc] = step(ch);
                int nr = r + rr, nc = c + cc;
                if (!inside(nr, nc))
                {
                    ans = {1, 1};
                }
                else
                {
                    ans = dfs(nr, nc);
                }
            }
            else if (ch == 'S')
            {
                vector<pair<int, int>> nxt;
                nxt.reserve(4);

                for (int z = 0; z < 4; z++)
                {
                    int nr = r + dr[z], nc = c + dc[z];
                    if (!inside(nr, nc))
                        continue;

                    char t = g[nr][nc];
                    if (t == 'X')
                    {
                        nxt.push_back({nr, nc});
                    }
                    else if (t == '^' || t == 'v' || t == '<' || t == '>')
                    {
                        auto [tr, tc] = step(t);
                        int br = r - nr, bc = c - nc;
                        if (!(tr == br && tc == bc))
                        {
                            nxt.push_back({nr, nc});
                        }
                    }
                }

                Frac sum = {0, 1};
                for (auto [nr, nc] : nxt)
                {
                    sum = addFrac(sum, dfs(nr, nc));
                }
                ans = divInt(sum, (int)nxt.size());
            }

            ans = norm(ans);
            memo[id] = ans;
            state[id] = 2;
            return ans;
        };

        Frac out = dfs(0, 0);
        out = norm(out);
        cout << toString128(out.p) << ' ' << toString128(out.q) << '\n';
    }

    return 0;
}
