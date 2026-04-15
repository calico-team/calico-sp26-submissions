#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
#define F first
#define S second
const int MM = 15;
int T, N, M;

string grid[MM+1];

int encode(int r, int c){
    return r*M + c;
}

pi decode(int tg){
    int c = tg%M, r = (tg-c) / M;
    return {r, c};
}

map<char, pi> dir = {
    {'v', {1, 0}},
    {'>', {0, 1}},
    {'<', {0, -1}},
    {'^', {-1, 0}},
};

vector<pi> cards = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

set<char> dirs = {'<', '>', 'v', '^'};

// returning a non-negative number means it's the tg, -1 means off grid, -2 means trash
int where_to(int r, int c){
    if (r < 1 || N < r || c < 1 || M < c) return -1;
    if (grid[r][c] == 'X') return -2;
    if (grid[r][c] == 'S') return encode(r, c);
    pi k = dir[grid[r][c]];
    int rr = r+k.F, cc = c+k.S;
    return where_to(rr, cc);
}

ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}

pi simplify(pi f){
    if (f.F == 0 && f.S == 0) return {0, 0};
    ll g = gcd(f.F, f.S);
    return {f.F / g, f.S / g};
}

pi add_frac(pi f1, pi f2){
    return simplify({f1.F*f2.S + f2.F*f1.S , f1.S * f2.S});
}

pi mult_frac(pi f1, pi f2){
    return simplify({f1.F*f2.F, f1.S*f2.S});
}

int ptr;
vector<int> ajl[MM*MM];
pi dp[MM+1][MM+1];

pi jojo(int r, int c){
    // off map
    if (r < 1 || N < r || c < 1 || M < c) return {1, 1};
    // trash
    if (grid[r][c] == 'X') return {0, 1};
    // solved already
    if (dp[r][c].F != -1) return dp[r][c];
    // not solved yet
    // splitter
    if (grid[r][c] == 'S'){
        int den = 0;
        pi sum = {0, 1};
        for (pi card : cards){
            int rr = r+card.F, cc = c+card.S;
            // next cell is on the map AND (either a deletor or a conveyer that doesn't point back)
            bool onMap = 1 <= rr && rr <= N && 1 <= cc && cc <= M;
            if (!onMap) continue;
            bool isDel = grid[rr][cc] == 'X';
            bool isGoodConv = false;

            if (dirs.count(grid[rr][cc])){
                pi gb = {card.F + dir[grid[rr][cc]].F, dir[grid[rr][cc]].S + card.S};
                isGoodConv = (gb.F != 0 || gb.S != 0);
            }

            if (onMap && (isDel || isGoodConv)){
                den += 1;
                sum = add_frac(sum, jojo(rr, cc));
            }
        }
        return dp[r][c] = simplify({sum.F, sum.S * den});
    } else { // direction
        pi d = dir[grid[r][c]];
        int rr = r+d.F, cc = c+d.S;
        return dp[r][c] = jojo(rr, cc);
    }
}

void solve(){
    cin >> N >> M;
    // resetting variables
    for (int r = 0; r <= N; r++){
        for (int c = 0; c <= M; c++){
            dp[r][c] = {-1, -1};
        }
    }

    for (int r = 1; r <= N; r++){
        cin >> grid[r]; grid[r] = " " + grid[r];
    }
    
    pi gb = jojo(1, 1);
    cout << gb.F << " " << gb.S << "\n";
}

int main(){
    cin >> T;
    for (; T > 0; T--) solve();
}