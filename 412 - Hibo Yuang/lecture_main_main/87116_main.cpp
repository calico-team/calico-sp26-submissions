#pragma GCC optimize("o3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

void __print(int x) {std::cerr << x;}
void __print(long x) {std::cerr << x;}
void __print(long long x) {std::cerr << x;}
void __print(unsigned x) {std::cerr << x;}
void __print(unsigned long x) {std::cerr << x;}
void __print(unsigned long long x) {std::cerr << x;}
void __print(float x) {std::cerr << x;}
void __print(double x) {std::cerr << x;}
void __print(long double x) {std::cerr << x;}
void __print(char x) {std::cerr << '\'' << x << '\'';}
void __print(const char *x) {std::cerr << '\"' << x << '\"';}
void __print(const std::string &x) {std::cerr << '\"' << x << '\"';}
void __print(bool x) {std::cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const std::pair<T, V> &x) {std::cerr << '{'; __print(x.first); std::cerr << ','; __print(x.second); std::cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; std::cerr << '{'; for(auto &i: x) std::cerr << (f++? "," : ""), __print(i); std::cerr << "}";}
void _print() {std::cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if(sizeof...(v)) std::cerr << ", "; _print(v...);}
#ifndef ONlINE_JUDGE
#define debug(x...) std::cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

using namespace __gnu_pbds;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x+= 0x9e3779b97f4a7c15;
        x = (x^(x>>30))*0xbf58476d1ce4e5b9;
        x = (x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = rng();
        return splitmix64(x+FIXED_RANDOM);
    }
};

template<typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using safe_set = std::unordered_set<T, custom_hash>;
template<typename T, typename V> using safe_map = std::unordered_map<T, V, custom_hash>;

const long long MOD = 1000000007;

struct mint {
    int v;
    mint() :v(0) {}
    mint(long long x) {
        if(x >= 0) v = x%MOD;
        else {
            x %= MOD;
            if(x < 0) x += MOD;
            v = x;
        }
    }

    friend std::ostream& operator<<(std::ostream& stream, const mint& x) { stream << x.v; return stream; }
    friend std::istream& operator>>(std::istream& stream, mint& val) { int x; stream >> x; val.v = x >= 0 ? x%MOD : x+(-x+MOD-1)/MOD*MOD; return stream; }
    operator int()const { return v; }
    mint& operator++() { if(++v >= MOD)v-= MOD; return *this; }
    mint& operator--() { if(--v < 0)v+= MOD; return *this; }
    mint& operator+=(const mint& y) { v = v+y.v-((v+y.v) >= MOD ? MOD : 0); return *this; }mint operator+(const mint& y)const { mint x = *this; return x+= y; }
    mint& operator-=(const mint& y) { v = v-y.v+(v-y.v < 0 ? MOD : 0); return *this; }mint operator-(const mint& y)const { mint x = *this; return x-= y; }
    mint& operator*=(const mint& y) { v = ((long long)v*y.v)%MOD; return *this; }mint operator*(const mint& y)const { mint x = *this; return x *= y; }
    mint& operator%=(const mint& y) { if(y.v)v %= y.v; return *this; }mint operator%(const mint& y)const { mint x = *this; return x %= y; }
    mint& operator/=(const mint& y) { return *this *= ModInverse(y.v); }mint operator/(const mint& y)const { return *this*ModInverse(y.v); }
    mint& operator^=(const mint& y) { *this = this->Pow(y); return *this; }mint Pow(int y)const { mint r = 1, x = v; for(y <<= 1; y >>= 1; x = x*x)if(y & 1)r = r*x; return r; }
    mint ModInverse(int a)const { return mint(a) ^ (MOD-2); }
    friend mint operator+(const mint& a, long long b) { return a+mint(b); }friend mint operator+(long long a, const mint& b) { return mint(a)+b; }friend mint operator+(const mint& a, int32_t b) { return a+mint(b); }friend mint operator+(int32_t a, const mint& b) { return mint(a)+b; }
    friend mint operator-(const mint& a, long long b) { return a-mint(b); }friend mint operator-(long long a, const mint& b) { return mint(a)-b; }friend mint operator-(const mint& a, int32_t b) { return a-mint(b); }friend mint operator-(int32_t a, const mint& b) { return mint(a)-b; }
    friend mint operator*(const mint& a, long long b) { return a*mint(b); }friend mint operator*(long long a, const mint& b) { return mint(a)*b; }friend mint operator*(const mint& a, int32_t b) { return a*mint(b); }friend mint operator*(int32_t a, const mint& b) { return mint(a)*b; }
    friend mint operator/(const mint& a, int32_t b) { return a/mint(b); }friend mint operator/(int32_t a, const mint& b) { return mint(a)/b; }friend mint operator/(const mint& a, long long b) { return a/mint(b); }friend mint operator/(long long a, const mint& b) { return mint(a)/b; }
    friend mint operator^(const mint& a, long long b) { return a.Pow(b); }friend mint operator^(long long a, const mint& b) { return mint(a).Pow(b); }friend mint operator^(const mint& a, int32_t b) { return a.Pow(b); }friend mint operator^(int32_t a, const mint& b) { return mint(a).Pow(b); }friend mint operator^(const mint& a, const mint& b) { return a.Pow(b); }
    bool operator==(const mint& y)const { return v == y.v; }bool operator==(int32_t y)const { return v == y; }bool operator==(long long y)const { return v == y; }
    bool operator!=(const mint& y)const { return v != y.v; }bool operator!=(int32_t y)const { return v != y; }bool operator!=(long long y)const { return v != y; }
    bool operator>(const mint& y)const { return v > y.v; }bool operator>(int32_t y)const { return v > y; }bool operator>(long long y)const { return v > y; }
    bool operator>=(const mint& y)const { return v >= y.v; }bool operator>=(int32_t y)const { return v >= y; }bool operator>=(long long y)const { return v >= y; }
    bool operator<(const mint& y)const { return v < y.v; }bool operator<(int32_t y)const { return v < y; }bool operator<(long long y)const { return v < y; }
    bool operator<=(const mint& y)const { return v <= y.v; }bool operator<=(int32_t y)const { return v <= y; }bool operator<=(long long y)const { return v <= y; }

    mint pow(long long e) const {
        mint base = *this, res = 1;
        while(e) {
            if(e & 1) res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }
    mint inv() const { return this->pow(MOD-2); }
};

const long long INF = 2000000000000000000;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    int t;
    std::cin >> t;

    while(t--) {
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<std::vector<int>> grid(n+1, std::vector<int>(m+1, 0));
        for(int i = 1; i <= n; ++i) {
            std::string s;
            std::cin >> s;

            for(int j = 1; j <= m; ++j) grid[i][j] = ((s[j-1] == '-') ? 1 : 0);
        }

        //rotate by 45 degrees, diff can be taken as max of dx dy
        std::vector<std::vector<int>> rotated(n+m+1, std::vector<int>(n+m+1, 0));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                rotated[i+j][i-j+m] = grid[i][j];
            }
        }

        //psums will quickly identify whether there are at least k empty seats in a square
        std::vector<std::vector<int>> psums(n+m+1, std::vector<int>(n+m+1, 0));
        for(int i = 1; i <= n+m; ++i) {
            for(int j = 1; j <= n+m; ++j) psums[i][j] = rotated[i][j]+psums[i-1][j]+psums[i][j-1]-psums[i-1][j-1];
        }

        auto brute = [&](int mid) -> std::array<int, 5> {
            for(int lx = 1; lx <= n+m; ++lx) {
                if(lx+mid > n+m) break;
                int rx = lx+mid;
                for(int ly = 1; ly <= n+m; ++ly) {
                    if(ly+mid > n+m) break;
                    int ry = ly+mid;
                    if(psums[rx][ry]-psums[lx-1][ry]-psums[rx][ly-1]+psums[lx-1][ly-1] >= k) return {1, lx, ly, rx, ry};
                }
            }

            return {0, 0, 0, 0, 0};
        };

        int lo = 0, hi = n+m, alx, aly, arx, ary;
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            auto res = brute(mid);
            if(res[0] == 1) {
                alx = res[1];
                aly = res[2];
                arx = res[3];
                ary = res[4];
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }

        int count = 0;
        for(int i = 1; i <= n && count < k; ++i) {
            for(int j = 1; j <= m && count < k; ++j) {
                if(!grid[i][j]) continue;

                int u = i+j, v = i-j+m;

                if(alx <= u && u <= arx && aly <= v && v <= ary) {
                    std::cout << i-1 << " " << j-1 << "\n";
                    ++count;
                }
            }
        }
    }

    return 0;
}