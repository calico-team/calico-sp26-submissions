#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t, a, b;
ll p;

ll f(int x, int y) {
    ll ans = 1;
    for(int i = 0; i < x; i++) {
        ans *= 2;
        if(ans > p) {
            return -1;
        }
    }
    for(int i = 0; i < y; i++) {
        ans *= 3;
        if(ans > p) {
            return -1;
        }
    }
    return ans;
}

void solve() {
    cin >> p >> a >> b;
    vector<vector<char>> g(3, vector<char>(500, '.'));
    vector<vector<ll>> arr(3, vector<ll>(500));
    g[0][0] = 'v';
    g[1][0] = '>';
    arr[1][0] = p;
    int split = 1;
    for(int i = 1; i <= a; i++) {
        g[1][split] = 'S';
        g[0][split] = '>';
        g[1][split+1] = '>';

        ll reduce = f(a-i, b);
        if(reduce != -1) {
            p -= reduce;
            g[0][split+1] = '^';
        } else {
            g[0][split+1] = 'X';
        }

        split += 2;
    }
    for(int i = 1; i <= b; i++) {
        g[1][split] = 'S';
        g[0][split] = '>';
        g[1][split+1] = '>';
        g[2][split] = '>';

        ll reduce = f(0, b-i);
        if(reduce != -1) {
            if(2*reduce <= p) {
                g[0][split+1] = '^';
                g[2][split+1] = 'v';
                p -= 2*reduce;
            } else if(reduce <= p) {
                g[0][split+1] = '^';
                g[2][split+1] = 'X';
                p -= reduce;
            }
        } else {
            g[0][split+1] = 'X';
            g[2][split+1] = 'X';
        }

        split += 2;
    }

    if(p == 1) {
        g[1][split] = '>';
    } else {
        g[1][split] = 'X';
    }

    cout << 3 << " " << split << "\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < split+1; j++) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}