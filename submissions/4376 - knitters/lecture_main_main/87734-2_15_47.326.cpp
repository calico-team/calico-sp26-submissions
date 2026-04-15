#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,bmi,bmi2,fma")
#define fs first
#define nd second
#define yes fout << "yes"
#define no fout << "no"
#define YES fout << "YES"
#define NO fout << "NO"
#define Yes fout << "Yes"
#define No fout << "No"
#define alice fout << "Alice"
#define bob fout << "Bob"
#undef min
#undef max
template<typename T, typename U>constexpr std::common_type_t<T, U> min(T a, U b) {return a < b ? a : b;}
template<typename A, typename B>constexpr std::pair<A, B> min(std::pair<A, B> a, std::pair<A, B> b) {return a < b ? a : b;}
template<typename T, typename U>constexpr std::common_type_t<T, U> max(T a, U b) {return a > b ? a : b;}
template<typename A, typename B>constexpr std::pair<A, B> max(std::pair<A, B> a, std::pair<A, B> b) {return a > b ? a : b;}
#define all(a) (a).begin(), (a).end()
#define forn(i) for(int64_t i=0; i<n; ++i)
#define forni for(int64_t i=0; i<n; ++i)
#define forin(i) for(int64_t i=1; i<=n; ++i)
#define forii for(int64_t i=1; i<=n; ++i)
#define fori(i, a) for(int64_t i=1; i<=a; ++i)
#define form(i, a) for(int64_t i=0; i<a; ++i)
#define forr(i, a, n) for(int64_t i = a; i < n; ++i)
#define ford(i,a,n) for(int64_t i = a; i >= n; --i)
#define forv(i, a) for(size_t i = 0; i < a.size(); ++i)
#define endl '\n'
#define endll fout << '\n'
#define sp ' '
#define spp fout << ' '
#define pb emplace_back
#define testcase int64_t testcase;fin>>testcase;while(testcase--)
#define cinn int64_t n;fin>>n
#define cinnk int64_t n,k;fin>>n>>k
#define cinnq int64_t n,q;fin>>n>>q
#define cinnm int64_t n,m;fin>>n>>m
#define cinns int64_t n;string s;fin>>n>>s
#define cinnmk int64_t n,m,k;fin>>n>>m>>k
#define cins string s;fin>>s;
#define cinx int64_t x;fin>>x
#define cina vi a(n);fin>>a;
#define cinall vll a(n);fin>>a;
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;
typedef pair<int32_t, int32_t> pii;
typedef pair<int64_t, int64_t> pll;
typedef map<int32_t, int32_t> mii;
typedef map<int64_t, int64_t> mll;
typedef set<int32_t> si;
typedef vector<pair<int32_t, int32_t>> vpii;
typedef vector<pair<int64_t, int64_t>> vpll;
typedef vector<vector<int32_t>> vii;
typedef vector<vector<bool>> vbb;
typedef vector<vector<int64_t>> vvll;
typedef vector<int64_t> vll;
typedef vector<uint64_t> vull;
typedef vector<int32_t> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
const int32_t MXN = 2e5 + 5;
const int32_t MOD = 1e9 + 7;
const int32_t MODD = 998244353;
const int32_t INF = 1000000000;
const int64_t LINF = 4000000000000000000LL;
template<typename I> void fastsort(I F,I L,bool R=0){using T=typename iterator_traits<I>::value_type;constexpr int B=sizeof(T)<3?8:sizeof(T)<5?9:11,M=(1<<B)-1;vector<T>U;vector<size_t>C(1<<B),P(1<<B);function<void(I,I,bool)>A=[&](I a,I b,bool S){if(b-a<2)return;if(S){I m=partition(a,b,[](T x){return x<0;});for(auto p=a;p!=m;++p)*p=-*p;A(a,m,0);A(m,b,0);for(auto p=a;p!=m;++p)*p=-*p;return;}T X=*max_element(a,b);int H=0,N=b-a;U.resize(N);while(X>>H){fill(C.begin(),C.end(),0);for(auto p=a;p!=b;++p)++C[(((T)*p>>H)&M)^R];P[0]=0;for(int i=1;i<=M;++i)P[i]=P[i-1]+C[i-1];for(auto p=a;p!=b;++p)U[P[(((T)*p>>H)&M)^R]++]=*p;move(U.begin(),U.begin()+N,a);H+=B;}};A(F,L,is_signed_v<T>);}
template <typename T> using uset = unordered_set<T>;
struct FastIn {static const int BUF = 1 << 20;char buf[BUF];int pos = 0, len = 0;inline char gc() {if (pos == len) {len = fread(buf, 1, BUF, stdin);pos = 0;if (len == 0) return EOF;}return buf[pos++];}
    template <typename T> inline typename enable_if<is_integral<T>::value>::type read(T &x) {x = 0; bool neg = false; char c = gc();while ((c < '0' || c > '9') && c != '-') { if (c == EOF) return; c = gc(); }if (c == '-') { neg = true; c = gc(); }while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = gc(); }if (neg) x = -x;}
    template <typename T> inline typename enable_if<is_floating_point<T>::value>::type read(T &x) {x = 0; bool neg = false; char c = gc();while ((c < '0' || c > '9') && c != '-' && c != '.') { if (c == EOF) return; c = gc(); }if (c == '-') { neg = true; c = gc(); }while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = gc(); }if (c == '.') {T frac = 1; c = gc();while (c >= '0' && c <= '9') { frac /= 10; x += (c - '0') * frac; c = gc(); }}if (neg) x = -x;}
    inline void read(string &s) {s.clear(); char c = gc();while (isspace(c)) c = gc();while (c != EOF && !isspace(c)) { s.push_back(c); c = gc(); }}
    inline void read(char &c) {c = gc();while (isspace(c)) c = gc();}
    template <typename A, typename B> inline void read(pair<A, B> &p) { read(p.first); read(p.second); }
    template <typename T> inline void read(vector<T> &v) { for (auto &x : v) read(x); }
    template <typename T> FastIn &operator>>(T &x) { read(x); return *this; }
} fin;

struct Fastout {static const int BUF = 1 << 20;char buf[BUF];int pos = 0;inline void pc(char c) {if (pos == BUF){flush();}buf[pos++] = c;}inline void flush() {fwrite(buf, 1, pos, stdout);pos = 0;}
    ~Fastout() { flush(); }
    template <typename T> inline typename enable_if<is_integral<T>::value>::type write(T x) {if (x == 0) { pc('0'); return; }if (x < 0) { pc('-'); x = -x; }char s[32]; int n = 0;while (x) { s[n++] = '0' + x % 10; x /= 10; }while (n--) pc(s[n]);}
    template <typename T> inline typename enable_if<is_floating_point<T>::value>::type write(T x, int prec = 6) {if (x < 0) { pc('-'); x = -x; }write((long long)x);x -= (long long)x;pc('.');for (int i = 0; i < prec; i++) {x *= 10;pc('0' + (int)x);x -= (int)x;}}
    inline void write(const string &s) { for (char c : s) pc(c); }inline void write(const char *s) { while (*s) pc(*s++); }inline void write(char c) { pc(c); }
    template <typename A, typename B> inline void write(const pair<A, B> &p) { write(p.first); pc(' '); write(p.second); }
    template <typename T> inline void write(const vector<T> &v) { for (auto &x : v) { write(x); pc(' '); } }
    template <typename T> inline void write(const set<T> &v) { for (auto &x : v) { write(x); pc(' '); } }
    template <typename T> Fastout &operator<<(const T &x) { write(x); return *this; }
} fout;
int n,m,k;
int sz;
vi pref;
int get(int x,int y){
    return x*sz+y;
}
int qry(int x1,int y1,int mid){
    int x2 = min(x1 + mid + 1,sz-1), y2 = min(y1 + mid + 1,sz-1);
    return pref[get(x2,y2)] - pref[get(x1,y2)] - pref[get(x2,y1)] + pref[get(x1,y1)];
}
pii check(int mid){
    form(i,sz-1)
        form(j,sz-1)
            if(qry(i,j,mid) >= k)
                return {i, j};
    return {-1, -1};
}
int32_t main(){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    testcase{
        fin >> n >> m >> k;
        sz = n+m;
        vs grid(n);
        fin >> grid;
        pref.assign(sz*sz,0);
        forni
            forn(j)
                if(grid[i][j] == '-')
                    pref[get(i+j+1,i-j+m)] = 1;
        fori(i,sz-1)
            fori(j,sz-1)
                pref[get(i,j)] += pref[get(i-1,j)] + pref[get(i,j-1)] - pref[get(i-1,j-1)];
        int l = 0, r = sz-1;
        while(l < r){
            int mid = l+(r-l)/2;
            auto [x, y] = check(mid);
            if(x != -1) r = mid;
            else l = mid+1;
        }
        auto [x1, y1] = check(l);
        int x2 = min(x1 + l, sz - 1), y2 = min(y1 + l, sz - 1);
        int cnt = 0;
        forni{
            if(cnt >= k) break;
            form(j,m){
                if(cnt >= k) break;
                if(grid[i][j] != '-') continue;
                int x = i+j,y = i+m-j-1;
                if(x1 <= x && x <= x2 && y1 <= y && y <= y2){
                    fout << i << sp << j << endl;
                    cnt++;
                }
            }
        }
    }   
}