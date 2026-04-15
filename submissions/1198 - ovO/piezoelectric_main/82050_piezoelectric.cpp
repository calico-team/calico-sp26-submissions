#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
template <class T> void debug_print(const vector<T>& v) {
    cout << "{";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) cout << ", ";
        cout << v[i];
    }
    cout << "}";
}
template <class A, class B> void debug_print(const pair<A, B>& p) {
    cout << "(";
    debug_print(p.first);
    cout << ", ";
    debug_print(p.second);
    cout << ")";
}
template <class T> void debug_print(const T& x) {
    cout << x;
}
void debug_out() {
    cout << '\n';
}
template <class T, class... Ts> void debug_out(T a, Ts... b) {
    debug_print(a);
    cout << ' ';
    debug_out(b...);
}
#else
#define dbg(...)
#endif

using ll = long long;

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

#define endl "\n"

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define each(x, v) for (auto& x : (v))

#define pb push_back
#define eb emplace_back

const int INF = 1000000000000000000LL; // 1e18
namespace helpers {
template <class T> bool chmax(T& a, T b, bool ok = true) {
    return ok && a < b ? a = b, 1 : 0;
}
template <class T> bool chmin(T& a, T b, bool ok = true) {
    return ok && b < a ? a = b, 1 : 0;
}
int cdiv(int a, int b) {
    return a / b + ((a ^ b) > 0 && a % b);
}
int fdiv(int a, int b) {
    return a / b - ((a ^ b) < 0 && a % b);
}

struct range_iter {
    int x, step;
    int operator*() const { return x; }
    void operator++() { x += step; }
    bool operator!=(const range_iter& o) const { return step > 0 ? x < o.x : x > o.x; }
};
struct range_view {
    int l, r, step;
    range_iter begin() const { return {l, step}; }
    range_iter end() const { return {r, step}; }
};

range_view range(int r) {
    return {0, r, 1};
}
range_view range(int l, int r, int step = 1) {
    assert(step != 0);
    return {l, r, step};
}

template <class T> void read_one(T& x) {
    cin >> x;
}
template <class A, class B> void read_one(pair<A, B>& p) {
    read_one(p.first);
    read_one(p.second);
}
template <class T> void read_one(vector<T>& v) {
    for (auto& x : v) read_one(x);
}
template <class... Ts> void read(Ts&... xs) {
    (read_one(xs), ...);
}

template <class... Ts> void print(const Ts&... xs) {
    ((cout << xs), ...);
}
template <class A, class B> void print(const pair<A, B>& p) {
    print(p.first, ' ', p.second);
}
template <class T> void print(const vector<T>& v, char sep = ' ') {
    for (int i = 0; i < (int)v.size(); i++) cout << (i ? string(1, sep) : "") << v[i];
}

template <class... Ts> void println(const Ts&... xs) {
    print(xs...);
    cout << '\n';
}
template <class T> void println(const vector<T>& v, char sep = ' ') {
    print(v, sep);
    cout << '\n';
}

void yesno(bool ok) {
    cout << (ok ? "YES\n" : "NO\n");
}
}; // namespace helpers
using namespace helpers;

void solve(int tc) {
    int l, w, e, r;
    read(l, w, e, r);

    int perim = (l + w) * 2;
    println(e / (r * perim));
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef FILEIO
    freopen(FILEIO ".in", "r", stdin);
    freopen(FILEIO ".out", "w", stdout);
#endif

    int t = 1;
    read(t);
    int tc = 1;
    while (t--) solve(tc++);

    return 0;
}
