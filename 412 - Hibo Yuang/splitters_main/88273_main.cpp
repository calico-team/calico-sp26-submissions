    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const ll MAX = 1e18;
    const ll MOD = 1e9 + 7;
    const ll MAX2 = 41, MAX3 = 27;
    bool testcases = true;
    map<char, pair<int, int>> lookup = {{'.',{0, 0}},{'S',{0, 0}}, {'X',{0, 0}}, {'>',{0, 1}}, {'<',{0, -1}}, {'^',{-1, 0}}, {'v',{1, 0}}};
    template<typename T>
    struct Frac {
        T n, d;
        Frac(): n(0), d(1) {}
        Frac(T n): n(n), d(1) {}
        Frac(T n, T d): n(n), d(d) {}
        Frac inv() const {return Frac(d, n);}
        Frac pow(ll k) const {return Frac(n.pow(k), d.pow(k));}
        Frac& operator+=(const Frac& r) {n=n*r.d+r.n*d,d*=r.d;return *this;}
        Frac& operator-=(const Frac& r) {n=n*r.d-r.n*d,d*=r.d;return *this;}
        Frac& operator*=(const Frac& r) {n*=r.n,d*=r.d;return *this;}
        Frac& operator/=(const Frac& r) {n*=r.d,d*=r.n;return *this;}
        Frac operator+(const Frac& r) const{return Frac(*this)+=r;}
        Frac operator-(const Frac& r) const{return Frac(*this)-=r;}
        Frac operator*(const Frac& r) const{return Frac(*this)*=r;}
        Frac operator/(const Frac& r) const{return Frac(*this)/=r;}
        template<typename U>Frac& operator+=(const U& r) {n+=d*r;return *this;}
        template<typename U>Frac& operator-=(const U& r) {n-=d*r;return *this;}
        template<typename U>Frac& operator*=(const U& r) {n*=r;return *this;}
        template<typename U>Frac& operator/=(const U& r) {d*=r;return *this;}
        template<typename U>Frac operator+(const U& r) const{return Frac(*this)+=r;}
        template<typename U>Frac operator-(const U& r) const{return Frac(*this)-=r;}
        template<typename U>Frac operator*(const U& r) const{return Frac(*this)*=r;}
        template<typename U>Frac operator/(const U& r) const{return Frac(*this)/=r;}
        friend ostream& operator<<(ostream& os, const Frac& f){return os<<f.n << " " << f.d;}
    };
    typedef Frac<__int128> frac;

    void solve() {
        int n, m; cin >> n >> m;
        vector<vector<char>> uwu(n, vector<char>(m));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> uwu[i][j];
        auto adj = [&](int x, int y, bool idk) {
            vector<pair<int, int>> res;
            for (auto [_, dir] : lookup) {
                if (dir == make_pair(0, 0)) continue;
                auto [dx, dy] = dir;
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (uwu[nx][ny] == '.') continue;
                if (idk && uwu[x][y] != '.' && (lookup[uwu[x][y]].first != dx || lookup[uwu[x][y]].second != dy) && uwu[nx][ny] == 'S') res.emplace_back(nx, ny);
                auto [checkx, checky] = lookup[uwu[nx][ny]];
                if ((nx + checkx == x && ny + checky == y) ^ idk) continue; // 1 to go interstellar, 0 to go outerstellar
                res.emplace_back(nx, ny);
            }
            return res;
        };
        vector<vector<int>> in(n, vector<int>(m));
        vector<vector<frac>> v(n, vector<frac>(m));
        v[0][0] = 1;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) in[i][j] = adj(i, j, true).size();
        queue<pair<int, int>> q;
        auto addnext = [&](int x, int y) {
            in[x][y]--;
            if (in[x][y] == 0) q.emplace(x, y);
        };
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (uwu[x][y] == 'X') continue;
            if (uwu[x][y] == 'S') {
                auto children = adj(x, y, false);
                for (auto [nx, ny] : children) {
                    v[nx][ny] += v[x][y]/children.size();
                    if (uwu[nx][ny] != 'X') addnext(nx, ny);
                }
            }
            else {
                auto [dx, dy] = lookup[uwu[x][y]];
                int nx = x+dx, ny = y+dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    __int128 num = v[x][y].n, dem = v[x][y].d, g = gcd(num, dem);
                    ll nnum = num/g, ndem = dem/g;
                    cout << nnum << " " << ndem << endl;
                    return;
                }
                v[nx][ny] += v[x][y];
                addnext(nx, ny);
            }
            int debugginglineidk = 0;
        }
        cout << "0 1" << endl;
    }

    int32_t main() {
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++) solve();
        return 0;
    }