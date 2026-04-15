#include <bits/stdc++.h>

using namespace std;

// Debugging helpers
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define f(i, n) for (ll i = 0; i < n; ++i)
#define i(a)           \
    for (auto &&i : a) \
        cin >> i;
#define YES                      \
    do                           \
    {                            \
        cout << "nah i'd win\n"; \
        return;                  \
    } while (0)
#define NO                        \
    do                            \
    {                             \
        cout << "nah i'd lose\n"; \
        return;                   \
    } while (0)

// Print
template <typename T>
void prnt(const T &val)
{
    if constexpr (std::is_arithmetic_v<T> || std::is_same_v<T, string>)
    {
        cout << val << '\n';
    }
    else
    {
        for (const auto &x : val)
            cout << x << ' ';
        cout << '\n';
    }
}
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    string a, b;
    cin >> a >> b;

    int i = 0, j = 0;
    int n = a.length(), m = b.length();

    for (int j = 0; j < m; j++)
    {
        while (i < n && a[i] != b[j])
        {
            a[i] = '#';
            i++;
        }
        i++;
    }

    while (i < n)
    {
        a[i] = '#';
        i++;
    }

    cout << a << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // createPrimeSieve(); countfact(); setFactors();
    int tc;
    cin >> tc; // Read number of test cases
    while (tc--)
    {
        solve();
    }
    return 0;
}