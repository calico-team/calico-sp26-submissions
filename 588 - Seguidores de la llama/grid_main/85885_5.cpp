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
        int n;
        cin >> n;
        vi a(n);
        forn(i, n) cin >> a[i];
        
        vi max_L, min_R;
        priority_queue<int> L;
        priority_queue<int, vi, greater<int>> R;
        
        forn(i, n) {
            L.push(a[i]);
            R.push(a[i]);
            while (L.top() > R.top()) {
                int l = L.top(), r = R.top();
                L.pop(); R.pop();
                L.push(r); R.push(l);
            }
            max_L.pb(L.top());
            min_R.pb(R.top());
            if (i < n - 1) {
                L.pop();
                R.pop();
            }
        }
        
        vi b(n);
        b[n - 1] = max_L[n - 1];
        dforn(i, n - 1) b[i] = max(max_L[i], min(min_R[i], b[i + 1]));
        
        forn(i, n) cout << b[i] << " \n"[i == n - 1];
    }
    
    return 0;
}
