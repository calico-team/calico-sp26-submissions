#include <iostream>
#include <vector>
#include<string>
#include <string>
#include <algorithm>
#include<utility>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <deque>
#include <math.h>
#include<random>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {

    if (a < b) {
        swap(a,b);
    }
    if (b == 1) {
        return 1;
    }
    if (b == 0) {
        return a;
    }
    a = a % b;
    return gcd(b,a);
}

pll travel(vector<string>& board, pll loc, ll n, ll m) {
    if (loc.first >= n || loc.first < 0 || loc.second < 0 || loc.second >= m) {
        return {1,1};
    }
    else if (board[loc.first][loc.second] == '>') {
        loc.second += 1;
        return travel(board,loc,n,m);
    }
    else if (board[loc.first][loc.second] == '<') {
        loc.second -=1;
        return travel(board,loc,n,m);

    }
    else if (board[loc.first][loc.second] == 'v') {
        loc.first += 1;
        return travel(board,loc,n,m);

    }
    else if (board[loc.first][loc.second] == '^') {
        loc.first -=1;
        return travel(board,loc,n,m);

    }
    else if (board[loc.first][loc.second] == 'S') {
        pll temp, p;
        p = {0,1};
        ll div = 0;
        if (loc.first+1 < n && board[loc.first + 1][loc.second] != '.' && board[loc.first + 1][loc.second] != '^') {
            temp = travel(board, {loc.first+1, loc.second}, n, m);
            p.first = p.first*temp.second + p.second*temp.first;
            p.second = temp.second * p.second;
            ll g = gcd(p.first, p.second);
            p.first = p.first/g;
            p.second = p.second/g;
            div++;
        }
        if (loc.first - 1 >= 0 && board[loc.first - 1][loc.second] != '.' && board[loc.first - 1][loc.second] != 'v') {
            temp = travel(board, {loc.first-1, loc.second}, n, m);
            p.first = p.first*temp.second + p.second*temp.first;
            p.second = temp.second * p.second;
            ll g = gcd(p.first, p.second);
            p.first = p.first/g;
            p.second = p.second/g;
            div++;
        }
        if (loc.second + 1 <m && board[loc.first][loc.second+1] != '.' && board[loc.first][loc.second+1] != '<') {
            temp = travel(board, {loc.first, loc.second+1}, n, m);
            p.first = p.first*temp.second + p.second*temp.first;
            p.second = temp.second * p.second;
            ll g = gcd(p.first, p.second);
            p.first = p.first/g;
            p.second = p.second/g;
            div++;
        }
        if (loc.second - 1 >=0 && board[loc.first][loc.second-1] != '.' && board[loc.first][loc.second-1] != '>') {
            temp = travel(board, {loc.first, loc.second-1}, n, m);
            p.first = p.first*temp.second + p.second*temp.first;
            p.second = temp.second * p.second;
            ll g = gcd(p.first, p.second);
            p.first = p.first/g;
            p.second = p.second/g;
            div++;
        }
        p.second *= div;
        return p;
    }
    else if (board[loc.first][loc.second] == 'X') {
        return {0,1};
    }

}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    vector<string> board;
    ll n, m;
    while (t--) {
        cin >> n >> m;
        board.resize(n);
        for (int i = 0; i<n; i++) {
            cin >> board[i];
        }
        pll ans;
        ans = travel(board, {0,0}, n, m);
        ll g = gcd(ans.first, ans.second);
        cout << ans.first/g << ' ' << ans.second/g << "\n";


    }


}