#include <bits/stdc++.h>
using namespace std;
#define int long long

// Function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int &x, int &y) {

    // Base Case 
    if (a == 0)  { 
        x = 0; 
        y = 1; 
        return b; 
    } 

    int x1, y1; 
    int gcd = gcdExtended(b%a, a, x1, y1); 

    // Update x and y using results of 
    // recursive call 
    x = y1 - (b/a) * x1; 
    y = x1; 
    return gcd; 
} 

int inv(int a, int m) {
    int x = 0, y = 0;
    int g = gcdExtended(a, m, x, y);
    return (x % m + m) % m;
}

void solve(){
    int k, n, m, p, q; cin >> k >> n >> m >> p >> q;

    vector<int> x(k), y(k);

    for(int i = 0; i < k; ++i){
        cin >> x[i] >> y[i];
    }

    int ans = -1, mint = INT_MAX;

    for(int i = 0; i < k; ++i){
        int dx = x[i] - x[0], dy = y[i] - y[0];

        dx %= n; dx += n; dx %= n;
        dy %= m; dy += m; dy %= m;

        int gcdx = gcd(q,n), gcdy = gcd(p,m);

        if(dx % gcdx != 0 || dy % gcdy != 0) continue;

        int nprime = n/gcdx, mprime = m/gcdy;

        int t0 = (dx/gcdx * inv(q/gcdx, nprime)) % nprime;
        int t1 = (dy/gcdy * inv(p/gcdy, mprime)) % mprime;

        int g = gcd(nprime,mprime);
        
        if((t0 - t1) % g != 0) continue;

        int lcmm = nprime * mprime / g;

        int fin = ((t1-t0)%mprime); fin += mprime; fin %= mprime;

        int nprimeprime = nprime/g, mprimeprime = mprime/g;

        int idx = (fin / g * inv(nprimeprime, mprimeprime)) % mprimeprime;
        int t = t0 + idx * nprime;

        if (t == 0) t = lcmm;

        if(t < mint){
            mint = t;
            ans = i;
        }

    }

    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--) solve();
}