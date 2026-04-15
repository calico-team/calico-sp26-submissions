#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> solve(ll P, int A, int B) {
    vector<int> v;
    for (int i = 0; i < A; i++) v.push_back(2);
    for (int i = 0; i < B; i++) v.push_back(3);
    
    int n = v.size();
    vector<int> d(n);
    ll p = P;
    
    for (int i = n - 1; i >= 0; i--) {
        d[i] = p % v[i];
        p /= v[i];
    }

    int m = 300;
    vector<string> f(5, string(m, '.'));
    
    f[0][0] = 'v'; 
    f[1][0] = 'v'; 
    f[2][0] = '>';
    
    int c = 1;
    for (int i = 0; i < n; i++) {
        f[2][c] = 'S';
        f[2][c + 1] = '>';
        int r = d[i];
        
        if (v[i] == 2) {
            if (r == 1) { 
                f[1][c] = '^'; f[0][c] = '^';
            } else { 
                f[3][c] = 'x';
            }
        } else {
            f[1][c] = '^'; f[3][c] = 'v';
            if (r == 0) { 
                f[0][c] = 'x'; f[4][c] = 'x'; 
            } else if (r == 1) { 
                f[0][c] = '^'; f[4][c] = 'x'; 
            } else { 
                f[0][c] = '^'; f[4][c] = 'v'; 
            }
        }
        c += 2;
    }

    if (p > 0) f[2][c] = '>'; 
    else f[2][c] = 'x';

    vector<string> res;
    for (int i = 0; i < 5; i++) res.push_back(f[i].substr(0, c + 1));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int P, A, B;
        cin >> P >> A >> B;
        vector<string> factory = solve(P, A, B);
        int N = (int) factory.size();
        int M = (int) factory[0].size();
        cout << N << ' ' << M << '\n';
        for (const string& row : factory) {
            cout << row << '\n';
        }
    }
    return 0;
}