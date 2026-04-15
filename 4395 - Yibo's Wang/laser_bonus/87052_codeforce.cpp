#include <bits/stdc++.h>
using namespace std;

#define int long long
map<char,pair<int,int>> ma;

int gcd(int a, int b)  {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    int x1, y1;
    int g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
int power(int x, int y, int M)  {
    if (y == 0)  return 1;
    int p = power(x, y / 2, M) % M;
    p = (p * p) % M;
    if (y%2 == 0)  {
        return p;
    } else  {
        return x*p % M;
    }
    return (y % 2 == 0) ? p : (x * p) % M; }
int modInverse(int A, int M)  {
    int x, y;
    int g = extgcd(A, M, x, y);
    x = (x % M + M) % M;
    return x;
}

pair<int,int> spit(int a, int b, int c)  {  //solve ax = b mod c
    b += 1000000*c;
    b %= c;
    int g = gcd(a, c);
    if (b % g != 0)  {
        return {-1, -1};
    }
    a /= g;
    b /= g;
    c /= g;
    int x = modInverse(a, c);
    return {x*b % c, c};
}

void solve()  {
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    int curmin = LLONG_MAX;
    int ind = -1;
    int curx, cury;
    vector<pair<int,int>> lis(k);
    for (int i = 0; i < k; i++)  {
        cin >> lis[i].first >> lis[i].second;
        if (i == 0)  {
            curx = lis[i].first;
            cury = lis[i].second;
        }
    }
    for (int i = 0; i < k; i++)  {
        pair<int,int> res1 = spit(q, -curx+lis[i].first, n);
        pair<int,int> res2 = spit(p, -cury+lis[i].second ,m);
        int r1 = res1.first;
        int m1 = res1.second;
        int r2 = res2.first;
        int m2 = res2.second;
        if (r1 == -1 || r2 == -1)  {
            continue;
        }
        if ((r2-r1) % gcd(m1, m2) == 0)  {
            int clcm = lcm(m1, m2);
            int ans = r1 + (r2-r1)/gcd(m1, m2)*modInverse(m1/gcd(m1, m2), m2/gcd(m1, m2))*(m1/gcd(m1, m2));
            ans %= clcm;
            if (ans == 0)  {
                ans = clcm;
            }
            if (ans < curmin)  {
                curmin = ans;
                ind = i;
            }
        }
    }
    cout << ind << endl;
}

signed main()   {
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}