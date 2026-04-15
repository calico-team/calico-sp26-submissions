// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ll long long
#define endl '\n'

struct fract{
    ll num, den;
    fract(ll num , ll den){
        this->num = num;
        this->den = den;
    }
    fract(){this->num=0; this->den=1;}
    fract simplify(){
        ll g = __gcd(this->den, this->num);
        this->den/=g;
        this->num/=g;
        return *this;
    }
    fract operator+(const fract b){
        ll a = this->num * b.den;
        ll bb = b.num * this->den;
        ll c = b.den * this->den;
        a += bb;
        return fract(a, c).simplify();
    }
    fract operator-(const fract b){
        ll a = this->num * b.den;
        ll bb = b.num * this->den;
        ll c = b.den * this->den;
        a -= bb;
        return fract(a, c).simplify();
    }
    fract operator*(const fract b){
        ll a = this->num * b.num;
        ll bb = this->den * b.den;
        return fract(a, bb).simplify();
    }
    void operator=(const fract b){
        this->num = b.num;
        this->den = b.den;
    }
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


    function< fract (int, int, int , int)> f =[&](int i, int j, int pi, int pj) -> fract {
        if(i < 0 or i >= n or j < 0 or j >= m) return fract(1, 1);
        fract ans;
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
                if(ni == pi and nj == pj) continue;
                if(board[ni][nj] == '.')continue;
                count ++ ;
            }

            for(auto [di, dj] : moves){
                int ni = i + di;
                int nj = j+ dj;
                if(ni == pi and nj == pj) continue;
                ans = ans + f(ni, nj, i, j) * fract(1, count);
            }
        }else{
            return fract(0, 1);
        }
        return ans;
    };


    auto ans = f(0,0, 0,0);
    ans.simplify();
    cout << ans.num << " " << ans.den << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1; cin>>t;
    while(t--)
        solve();
}
