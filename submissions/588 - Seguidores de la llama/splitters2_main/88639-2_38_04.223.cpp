#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define dforn(i, n) dforsn(i, 0, n)
 
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vb = vector<bool>;
using pll = pair<ll, ll>;
using bint = __int128;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
#define pb push_back
#define eb emplace_back
 
#define fst first
#define snd second
 
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    forn(_, t) {
        ll P, A, B;
        cin >> P >> A >> B;
        
        vll base;
        forn(i, B) base.pb(3);
        forn(i, A) base.pb(2);
        
        vll digits(A + B);
        forn(i, sz(base)) {
            digits[i] = P % base[i];
            P /= base[i];
        }
        
        if (P != 0) {
            cout << "1 1\nv\n";
            continue;
        }
        
        reverse(all(digits));
        
        vector<string> grid(44, string(44, '.'));
        
        grid[0][0] = '>';
        grid[0][1] = '>';
        grid[0][2] = 'v';
        grid[1][2] = 'v';
        
        forsn(i, 2, 44) grid[i][0] = 'v';
        
        int pos = 2;
        forn(i, A) {
            grid[pos][2] = 'S';
            grid[pos][1] = digits[i] == 0 ? 'X' : '<';
            grid[pos + 1][2] = 'v';
            grid[pos][0] = 'v';
            grid[pos][0] = 'v';
            pos += 2;
        }
        
        int delta = 0;
        forn(i, B) {
            grid[pos][2 + delta] = 'S';
            grid[pos][1 + delta] = digits[A + i] == 2 ? '<' : 'X';
            forsn(j, 1, delta + 1) grid[pos][j] = '<';
            grid[pos + 1][2 + delta] = digits[A + i] >= 1 ? '<' : 'X';
            forsn(j, 1, delta + 2) grid[pos + 1][j] = '<';
            grid[pos][3 + delta] = 'v';
            grid[pos + 1][3 + delta] = 'v';
            pos += 2, delta++;
        }
        
        cout << sz(grid) << " " << sz(grid[0]) << "\n";
        forn(i, sz(grid)) cout << grid[i] << "\n";
    }
    
    return 0;
}
