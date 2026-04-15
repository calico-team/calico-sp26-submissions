#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll gcd(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll residue(ll x, ll y){
    return (x % y + y) % y;
}

ll inverse(ll a, ll m){
    ll x, y;
    ll g = gcd(a, m, x, y);
    if(g != 1){
        return -1;    
    }else
        return residue(x, m);
}

ll crt(ll a1, ll m1, ll a2, ll m2){
    ll factor = __gcd(m1, m2);
    if(residue(a1, factor) != residue(a2, factor))
        return -1;

    m1 /= factor; a1 = residue(a1, m1);
    ll n1 = inverse(m1, m2), n2 = inverse(m2, m1);
    ll a = a1*n2*m2 + a2*n1*m1;
    return residue(a, m1*m2);
}

void program(){
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q; // n, q across the x axis
    int x[k], y[k];

    int gcdnq = __gcd(n, q), gcdmp = __gcd(m, p),
        qnew = q / gcdnq, nnew = n / gcdnq,
        pnew = p / gcdmp, mnew = m / gcdmp;

    ll mint = LLONG_MAX, mini;
    for(int i = 0; i < k; ++i){
        cin >> x[i] >> y[i];
        if((x[i] - x[0]) % gcdnq != 0 || (y[i] - y[0]) % gcdmp != 0)
            continue;
        
        ll xnew = (x[i] - x[0]) / gcdnq, ynew = (y[i] - y[0]) / gcdmp,
            a = residue((xnew * inverse(qnew, nnew)), nnew), b = residue(ynew * inverse(pnew, mnew), mnew);
        
        ll t = crt(a, nnew, b, mnew);
        if(t == 0)
            t = 1LL*nnew*mnew/__gcd(nnew, mnew);
        if(t < mint && t != -1){
            mint = t;
            mini = i;
        }

        // cout << "xnew ynew a b t: " << xnew << ' ' << ynew << ' ' << a << ' ' << b << ' ' << t << endl;
    }

    cout << mini << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        program();
    }

    return 0;
}