#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

static const int BS = 1 << 20;
static char ibuf[BS];
static int ip = 0, ilen = 0;

inline char gc()
{
    if (ip >= ilen)
    {
        ilen = (int)fread(ibuf, 1, BS, stdin);
        ip = 0;
        if (ilen <= 0)
        {
            return 0;
        }
    }
    return ibuf[ip++];
}

template <class T>
bool rd(T &out)
{
    char c = gc();
    if (!c)
    {
        return false;
    }

    while (c != '-' && (c < '0' || c > '9'))
    {
        c = gc();
        if (!c)
        {
            return false;
        }
    }

    T sign = 1;
    if (c == '-')
    {
        sign = -1;
        c = gc();
    }

    T x = 0;
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = gc();
    }

    out = x * sign;
    return true;
}

struct Edge
{
    int u, v, val, w;
    double lv, fw;
};

static vector<double> fit(const vector<Edge> &e, int n, const vector<char> &dead, int iters, bool useSqrtW)
{
    vector<double> x(n, 0.0), nx(n, 0.0), num(n, 0.0), den(n, 0.0);
    const double alpha = 0.85;
    const double mx = log(1e9);

    rep(it, iters)
    {
        fill(all(num), 0.0);
        fill(all(den), 0.0);

        rep(i, e.size())
        {
            if (!dead.empty() && dead[i])
            {
                continue;
            }
            int a = e[i].u, b = e[i].v;
            double w = (useSqrtW ? e[i].fw : (double)e[i].w);

            den[a] += w;
            num[a] += w * (e[i].lv - x[b]);

            den[b] += w;
            num[b] += w * (e[i].lv - x[a]);
        }

        rep(i, n)
        {
            double target = (den[i] > 0.0 ? num[i] / den[i] : 0.0);
            double y = alpha * target + (1.0 - alpha) * x[i];
            if (y < 0.0)
            {
                y = 0.0;
            }
            if (y > mx)
            {
                y = mx;
            }
            nx[i] = y;
        }

        x.swap(nx);
    }

    return x;
}

static void makeA(const vector<double> &x, vector<ll> &a)
{
    const ll LIM = 1000000000LL;
    rep(i, x.size())
    {
        ll v = (ll)llround(expl((ld)x[i]));
        if (v < 1)
        {
            v = 1;
        }
        if (v > LIM)
        {
            v = LIM;
        }
        a[i] = v;
    }
}

static ld evalPick(
    const vector<Edge> &e,
    const vector<ll> &a,
    int d,
    vector<ld> &err,
    vector<int> &discard)
{
    int m = (int)e.size();
    err.assign(m, 0.0L);

    ld total = 0.0L;
    rep(i, m)
    {
        ld prod = (ld)a[e[i].u] * (ld)a[e[i].v];
        ld diff = fabsl(prod - (ld)e[i].val);
        err[i] = (ld)e[i].w * (diff / (ld)e[i].val);
        total += err[i];
    }

    discard.clear();
    if (d <= 0)
    {
        return total;
    }

    vector<int> id(m);
    iota(all(id), 0);
    if (d < m)
    {
        nth_element(id.begin(), id.begin() + d, id.end(), [&](int x, int y)
                    { return err[x] > err[y]; });
        id.resize(d);
    }

    ld removed = 0.0L;
    for (int idx : id)
    {
        removed += err[idx];
    }

    discard.swap(id);
    return total - removed;
}

static void coordRefine(
    const vector<Edge> &e,
    const vector<vector<int>> &adj,
    vector<ll> &a,
    const vector<char> &dead,
    int sweeps)
{
    vector<pair<double, double>> pts;

    rep(sw, sweeps)
    {
        bool any = false;

        rep(i, adj.size())
        {
            pts.clear();
            pts.reserve(adj[i].size());

            double totalW = 0.0;
            for (int id : adj[i])
            {
                if (dead[id])
                {
                    continue;
                }

                const Edge &ed = e[id];
                int j = ed.u ^ ed.v ^ i;

                double aj = (double)a[j];
                double target = (double)ed.val / aj;
                double wt = (double)ed.w * aj / (double)ed.val;
                pts.pb({target, wt});
                totalW += wt;
            }

            if (pts.empty() || totalW <= 0.0)
            {
                continue;
            }

            sort(all(pts), [](const pair<double, double> &L, const pair<double, double> &R)
                 { return L.first < R.first; });

            double pref = 0.0;
            double med = pts.back().first;
            for (auto &p : pts)
            {
                pref += p.second;
                if (pref * 2.0 >= totalW)
                {
                    med = p.first;
                    break;
                }
            }

            ll nv = (ll)llround(med);
            if (nv < 1)
            {
                nv = 1;
            }
            if (nv > 1000000000LL)
            {
                nv = 1000000000LL;
            }

            if (nv != a[i])
            {
                a[i] = nv;
                any = true;
            }
        }

        if (!any)
        {
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll D;
    if (!rd(n) || !rd(m) || !rd(D))
    {
        return 0;
    }

    vector<Edge> e;
    e.reserve(m);

    rep(i, m)
    {
        int r, c, v, w;
        rd(r);
        rd(c);
        rd(v);
        rd(w);
        r--;
        c--;

        Edge cur;
        cur.u = r;
        cur.v = c;
        cur.val = v;
        cur.w = w;
        cur.lv = log((double)v);
        cur.fw = sqrt((double)w);
        e.pb(cur);
    }

    int d = (int)min<ll>(D, m);

    vector<ll> bestA(n, 1), curA(n, 1);
    vector<int> bestDiscard;
    vector<int> curDiscard;
    vector<ld> err;
    ld bestScore = numeric_limits<ld>::infinity();

    auto relax = [&](const vector<ll> &candA, const vector<int> &candDiscard, ld score)
    {
        if (score + 1e-15L < bestScore)
        {
            bestScore = score;
            bestA = candA;
            bestDiscard = candDiscard;
        }
    };

    if (d == m)
    {
        bestDiscard.resize(m);
        iota(all(bestDiscard), 0);
    }
    else
    {
        vector<int> deg(n, 0);
        for (auto &ed : e)
        {
            deg[ed.u]++;
            deg[ed.v]++;
        }

        vector<vector<int>> adj(n);
        rep(i, n)
        {
            adj[i].reserve(deg[i]);
        }
        rep(i, m)
        {
            adj[e[i].u].pb(i);
            adj[e[i].v].pb(i);
        }

        vector<char> dead(m, 0);
        vector<char> none;

        makeA(fit(e, n, none, 12, true), curA);
        ld curScore = evalPick(e, curA, d, err, curDiscard);
        relax(curA, curDiscard, curScore);

        if (d > 0)
        {
            rep(round, 4)
            {
                fill(all(dead), 0);
                for (int id : curDiscard)
                {
                    dead[id] = 1;
                }

                coordRefine(e, adj, curA, dead, 2);
                curScore = evalPick(e, curA, d, err, curDiscard);
                relax(curA, curDiscard, curScore);
            }

            fill(all(dead), 0);
            for (int id : curDiscard)
            {
                dead[id] = 1;
            }

            makeA(fit(e, n, dead, 12, true), curA);
            curScore = evalPick(e, curA, d, err, curDiscard);
            relax(curA, curDiscard, curScore);
        }

        makeA(fit(e, n, none, 8, false), curA);
        curScore = evalPick(e, curA, d, err, curDiscard);
        relax(curA, curDiscard, curScore);

        if (d > 0)
        {
            fill(all(dead), 0);
            for (int id : curDiscard)
            {
                dead[id] = 1;
            }

            coordRefine(e, adj, curA, dead, 1);
            curScore = evalPick(e, curA, d, err, curDiscard);
            relax(curA, curDiscard, curScore);
        }

        sort(all(bestDiscard));
    }

    rep(i, n)
    {
        if (i)
        {
            cout << ' ';
        }
        cout << bestA[i];
    }
    cout << '\n';

    cout << bestDiscard.size();
    for (int id : bestDiscard)
    {
        cout << ' ' << (id + 1);
    }
    cout << '\n';

    return 0;
}
