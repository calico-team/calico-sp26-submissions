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

int median(int a, int b, int c) {
    array<int, 3> arr = {a, b, c};
    sort(arr.begin(), arr.end());
    return arr[1];
}

signed main()
{
    int tst;
    cin >> tst;
    while (tst --)
    {
        int n;
        cin >> n;

        V<int> a(n);
        read(a);

        V<int> b(n);
        b[0] = a[0];
        for (int i = 1; i < n; i ++) b[i] = median(b[i-1], a[i], i < n - 1 ? a[i+1] : inf);

        show(b);
    }
}
