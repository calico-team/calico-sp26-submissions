#include <bits/stdc++.h>

using namespace std;
#define double long double
#define int long long
#define V vector

const int inf = numeric_limits<int>::max();
const double infd = numeric_limits<double>::infinity();
using pii = pair<int, int>;
using pil = pair<int, double>;
using pli = pair<double, int>;
using pll = pair<double, double>;

#define F first
#define S second
#define PB push_back
#define read(arr) for (auto &x : arr) cin >> x
#define show(arr) for (auto x : arr) cout << x << " "; cout << endl
#define FOR(v,l,h) for (int v = l; v < h; v ++)

signed main()
{
    int tst;
    cin >> tst;
    while (tst --)
    {
        int n, p, r, k;
        cin >> n >> p >> r >> k;

        V<int> e(n);
        read(e);

        bool win = true;
        for (int i = 0; i < n; i ++)
        {
            int x = e[i];
            if (i % k == 0 && i != 0) p += r;
            if (x <= p)
            {
                p -= x;
            }
            else win = false;
        }
        cout << "nah i'd " << (win ? "win" : "lose") << endl;
    }
}
