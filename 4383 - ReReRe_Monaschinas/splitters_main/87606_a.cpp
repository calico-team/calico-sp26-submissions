// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ll long long
#define endl '\n'

struct fract {
    ll num, den;

    fract(ll num, ll den) : num(num), den(den) {
        normalize();
    }
    fract() : num(0), den(1) {}

    void normalize() {
        if (den < 0) { num = -num; den = -den; }
        ll g = (num == 0) ? den : __gcd(abs(num), abs(den));
        num /= g;
        den /= g;
    }

    fract operator+(const fract& b) const {
        ll g = __gcd(den, b.den);
        ll lcm = den / g * b.den;
        return fract(num * (lcm / den) + b.num * (lcm / b.den), lcm);
    }

    fract operator-(const fract& b) const {
        ll g = __gcd(den, b.den);
        ll lcm = den / g * b.den;
        return fract(num * (lcm / den) - b.num * (lcm / b.den), lcm);
    }

    fract operator*(const fract& b) const {
        ll g1 = __gcd(abs(num), abs(b.den));
        ll g2 = __gcd(abs(b.num), abs(den));
        return fract((num / g1) * (b.num / g2), (den / g2) * (b.den / g1));
    }

    fract operator/(const fract& b) const {
        return (*this) * fract(b.den, b.num);
    }

    bool operator==(const fract& b) const { return num == b.num && den == b.den; }
    bool operator< (const fract& b) const { return num * b.den < b.num * den; }
};

vector<pair<int,int>> moves = {{1,0}, {0,1},{-1, 0}, {0, -1}};

void solve(){

    int n,m;cin>>n>>m;

    vector<vector<char>>board(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0 ;j<m; j++){
            cin >> board[i][j];
        }
    }

    vector<vector<fract>>dp(n, vector<fract>(m, fract(-1, 1)));

    auto pointsBack = [&](int ni, int nj, int i, int j) -> bool {
        char c = board[ni][nj];
        if (ni == i+1 && c == '^') return true; 
        if (ni == i-1 && c == 'v') return true;
        if (nj == j+1 && c == '<') return true;
        if (nj == j-1 && c == '>') return true;
        return false;
    };


    function< fract (int, int, int , int)> f =[&](int i, int j, int pi, int pj) -> fract {
        if(i < 0 or i >= n or j < 0 or j >= m) return fract(1, 1);
        if(!(dp[i][j]==fract(-1, 1))) {
            return dp[i][j];
        }
        fract ans = {0, 1};
        if(board[i][j] == 'v'){
            ans = ans + f(i+1, j, i, j);
        }else if(board[i][j] =='^'){
            ans = ans + f(i-1, j, i, j);
        }else if(board[i][j] =='>'){
            ans = ans + f(i, j+1, i, j);
        }else if(board[i][j] =='<'){
            ans = ans + f(i, j-1, i, j);
        }else if(board[i][j] == 'S') {
            int count =0;
            for(auto [di, dj] : moves){
                int ni = i + di;
                int nj = j+ dj;
                if(pointsBack(ni, nj, i, j)) continue;
                if(board[ni][nj] == '.')continue;
                count ++ ;
            }

            for(auto [di, dj] : moves){
                int ni = i + di;
                int nj = j+ dj;
                if(pointsBack(ni, nj, i, j)) continue;
                if(board[ni][nj] == '.')continue;
                ans = ans + f(ni, nj, i, j) * fract(1, count);
            }
        }else{
            return fract(0, 1);
        }
        return dp[i][j] = ans;
    };


    auto ans = f(0,0, 0,0);
    ans.normalize();
    cout << ans.num << " " << ans.den << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1; cin>>t;
    while(t--)
        solve();
}
