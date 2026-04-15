#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
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

static vector<double> fit(const vector<Edge> &e, int n, const vector<char> &dead, int iters)
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
            double w = e[i].fw;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll D;
    if (!rd(n))
    {
        return 0;
    }
    rd(m);
    rd(D);

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
    vector<ll> a(n, 1);
    vector<int> discard;
    vector<ld> err(m, 0.0L);

    auto makeA = [&](const vector<double> &x)
    {
        const ll LIM = 1000000000LL;
        rep(i, n)
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
    };

    auto calcErr = [&]()
    {
        rep(i, m)
        {
            ld prod = (ld)a[e[i].u] * (ld)a[e[i].v];
            ld diff = fabsl(prod - (ld)e[i].val);
            err[i] = (ld)e[i].w * (diff / (ld)e[i].val);
        }
    };

    auto pickWorst = [&](int k)
    {
        if (k <= 0)
        {
            return vector<int>{};
        }
        vector<int> id(m);
        iota(all(id), 0);
        if (k < m)
        {
            nth_element(id.begin(), id.begin() + k, id.end(), [&](int a, int b)
                        { return err[a] > err[b]; });
            id.resize(k);
        }
        sort(all(id));
        return id;
    };

    if (d == m)
    {
        discard.resize(m);
        iota(all(discard), 0);
    }
    else if (d == 0)
    {
        vector<char> dead;
        makeA(fit(e, n, dead, 16));
    }
    else
    {
        vector<char> dead(m, 0);

        rep(round, 5)
        {
            makeA(fit(e, n, dead, 8));
            calcErr();

            vector<int> nd = pickWorst(d);
            if (nd == discard)
            {
                break;
            }
            discard.swap(nd);

            fill(all(dead), 0);
            for (int id : discard)
            {
                dead[id] = 1;
            }
        }

        makeA(fit(e, n, dead, 10));
        calcErr();
        discard = pickWorst(d);
    }

    rep(i, n)
    {
        if (i)
        {
            cout << ' ';
        }
        cout << a[i];
    }
    cout << '\n';

    cout << discard.size();
    for (int id : discard)
    {
        cout << ' ' << (id + 1);
    }
    cout << '\n';

    return 0;
}
