#include <bits/stdc++.h>
using namespace std;

char arr[16][16];
pair<long,long> a[16][16];
pair<long,long> ans = {0,1};
long n,m;

pair<long,long> f(pair<long,long> a) {
    long g = gcd(a.first,a.second);
    return {a.first/g,a.second/g};
}

pair<long,long> add(pair<long,long> a, pair<long,long> b) {
    pair<long,long> c = {a.first*b.second+a.second*b.first,a.second*b.second};
    return f(c);
}

pair<long,long> divide(pair<long,long> a, long b) {
    return f({a.first,a.second*b});
}

void g(long i, long j, pair<long,long> v) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        ans = add(ans,v);
        return;
    }
    if (arr[i][j] == 'X') {
        return;
    }
    a[i][j] = add(a[i][j],v);
}

long check(long i, long j, char c) {
    if (i >= 0 && i < n && j >= 0 && j < m) {
        if (arr[i][j] != c && (arr[i][j] == '<' || arr[i][j] == '>' || arr[i][j] == '^' || arr[i][j] == 'v' || arr[i][j] == 'X')) {
            return 1;
        }
    }
    return 0;
}



int main() {
    long t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (long i = 0; i < n; i++) {
            for (long j = 0; j < m; j++) {
                cin >> arr[i][j];
                a[i][j] = {0,1};
            }
        }
        ans = {0,1};
        a[0][0] = {1,1};
        for (long i = 0; i <= n*m; i++) {
            for (long j = 0; j < n; j++) {
                for (long k = 0; k < m; k++) {
                    if (a[j][k].first != 0) {
                        if (arr[j][k] == '^') {
                            g(j-1,k,a[j][k]);
                            a[j][k] = {0,1};
                        }
                        if (arr[j][k] == 'v') {
                            g(j+1,k,a[j][k]);
                            a[j][k] = {0,1};
                        }
                        if (arr[j][k] == '>') {
                            g(j,k+1,a[j][k]);
                            a[j][k] = {0,1};
                        }
                        if (arr[j][k] == '<') {
                            g(j,k-1,a[j][k]);
                            a[j][k] = {0,1};
                        }
                        if (arr[j][k] == 'X') {
                            a[j][k] = {0,1};
                        }
                        if (arr[j][k] == 'S') {
                            long count = check(j-1,k,'v') + check(j+1,k,'^') + check(j,k-1,'>') + check(j,k+1,'<');
                            if (check(j-1,k,'v')) {
                                g(j-1,k,divide(a[j][k],count));
                            }
                            if (check(j+1,k,'^')) {
                                g(j+1,k,divide(a[j][k],count));
                            }
                            if (check(j,k-1,'>')) {
                                g(j,k-1,divide(a[j][k],count));
                            }
                            if (check(j,k+1,'<')) {
                                g(j,k+1,divide(a[j][k],count));
                            }
                            a[j][k] = {0,1};
                        }
                    }
                }
            }
        }
        cout << ans.first << " " << ans.second << "\n";
    }
}