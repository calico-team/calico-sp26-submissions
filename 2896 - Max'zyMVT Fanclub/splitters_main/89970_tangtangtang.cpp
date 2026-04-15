#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <numeric>
#include <array>
#include <iomanip> // cout << fixed << setprecision(n);
#include <cmath>

using namespace std;
const bool TEST_CASE = true;

template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* name, T value) {
    std::cout << name << " : " << value << '\n';
}

template<typename T, typename... Args>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* names, T value, Args... args){
    const char* comma = strchr(names, ',');
    std::cout.write(names, comma - names) << " : " << value << " | ";
    Debug(comma + 1, args...);
}
template<typename T> 
ostream& operator<<(ostream& out, vector<T> &a){
    for (auto &x : a) out << x << ' '; 
    return out;
};

#ifdef DORMON
    #define debug(...) Debug(#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...) 
#endif

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

struct Fraction {
    int64_t n, d;
    void simplify(){
        if (d < 0){n = -n, d = -d;}
        int64_t g = gcd(abs(n), abs(d));
        n /= g; d /= g;
    }
    Fraction(int64_t _n = 0, int64_t _d = 1) : n(_n), d(_d) {simplify();}
    Fraction operator+(const Fraction& o) const {return Fraction(n * o.d + o.n * d, d * o.d);}
    Fraction operator-(const Fraction& o) const {return Fraction(n * o.d - o.n * d, d * o.d);}
    Fraction operator*(const Fraction& o) const {return Fraction(n * o.n, d * o.d);}
    Fraction operator/(const Fraction& o) const {return Fraction(n * o.d, d * o.n);}
    bool operator<(const Fraction& o) const {return n * o.d < o.n * d;}
    bool operator==(const Fraction& o) const {return n == o.n && d == o.d;}
    bool operator!=(const Fraction& o) const {return n != o.n || d != o.d;}
    friend ostream& operator<<(ostream& os, const Fraction& f){return (f.d == 1)?(os << f.n):(os << f.n << "/" << f.d);}
};
using frac = Fraction;
int n, m;

vector<vector<frac>> dp;
vector<string> grid;

void init(){
    dp.assign(n + 1, vector<frac>(m + 1, frac(-1, 1)));
    grid.resize(n);
}

bool out(int i, int j){
    return i >= n || i < 0 || j >= m || j < 0;
}
int mv(char c){
    if (c == '^') return 0;
    if (c == 'v') return 1;
    if (c == '>') return 2;
    if (c == '<') return 3;
    return 4;
}

frac dfs(int i, int j){
    if (out(i, j)) return frac(1, 1);
    if (dp[i][j] != frac(-1, 1)) return dp[i][j];
    if (grid[i][j] == 'X') return frac(0, 1);
    if (grid[i][j] == '^') return dfs(i - 1, j);
    if (grid[i][j] == 'v') return dfs(i + 1, j);
    if (grid[i][j] == '>') return dfs(i, j + 1);
    if (grid[i][j] == '<') return dfs(i, j - 1);
    if (grid[i][j] == 'S'){
        frac cc = frac(0, 1);
        int cnt = 0;
        if (grid[i - 1][j] == 'X' || (grid[i - 1][j] != 'v' && grid[i - 1][j] != '.')){
            cc = cc + dfs(i - 1, j);
            cnt++;
        }
        if (grid[i + 1][j] == 'X' || (grid[i + 1][j] != '^' && grid[i + 1][j] != '.')){
            cc = cc + dfs(i + 1, j);
            cnt++;
        }
        if (grid[i][j - 1] == 'X' || (grid[i][j - 1] != '>' && grid[i][j - 1] != '.')){
            cc = cc + dfs(i, j - 1);
            cnt++;
        }
        if (grid[i][j + 1] == 'X' || (grid[i][j + 1] != '<' && grid[i][j + 1] != '.')){
            cc = cc + dfs(i, j + 1);
            cnt++;
        }
        if (cnt == 0) cc = frac(0, 1);
        else cc = cc * frac(1, cnt);
        return dp[i][j] = cc;
    }
    return dp[i][j] = frac(0, 1);
}

void solve(){
    cin >> n >> m;
    init();
    for (auto &e:grid) cin >> e;
    frac ans = dfs(0, 0);
    cout << ans.n << ' ' << ans.d << '\n';
}


int main()
{
    #ifndef DORMON
        ios_base::sync_with_stdio(false); 
    #endif
    cin.tie(0);
    int q = 1; 
    if (TEST_CASE) cin >> q;
    while (q--){
        solve();
    }
}