#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int T, N, M;
const int maxn = 16;
char grid[maxn][maxn];
struct frac {
    int n, d;
    frac(int n, int d) : n(n), d(d) {}
    frac() : n(0), d(0) {}
};
frac mem[maxn][maxn];
int gcd(int n1, int n2) {
    if (n1 == 0)
        return n2;
    return gcd(n2 % n1, n1);
}
frac reduce(frac a) {
    int g = gcd(a.d, a.n);
    a.d /= g;
    a.n /= g;
    return a;
}
frac mul(frac a, frac b) {
    return frac(a.n * b.n, a.d * b.d);
}
frac add(frac a, frac b) {
    int den = a.d * b.d / gcd(a.d, b.d);
    int num = a.n * den / a.d + b.n * den / b.d;
    return frac(num, den);
}
frac dfs(int i, int j) {
    if (mem[i][j].d != 0)
        return mem[i][j];
    if (grid[i][j] == 'X')
        return mem[i][j] = frac(0, 1);
    if (grid[i][j] == '^') {
        // if leaving grid
        if (i == 1)
            return mem[i][j] = frac(1, 1);
        // if going into deletor
        if (grid[i - 1][j] == 'X')
            return mem[i][j] = frac(0, 1);
        // otherwise dfs
        return mem[i][j] = reduce(dfs(i - 1, j));
    } else if (grid[i][j] == 'v') {
        // if leaving grid
        if (i == N)
            return mem[i][j] = frac(1, 1);
        // otherwise dfs
        return mem[i][j] = reduce(dfs(i + 1, j));
    } else if (grid[i][j] == '<') {
        // if leaving grid
        if (j == 1)
            return mem[i][j] = frac(1, 1);
        // otherwise dfs
        return mem[i][j] = reduce(dfs(i, j - 1));
    } else if (grid[i][j] == '>') {
        // if leaving grid
        if (j == M)
            return mem[i][j] = frac(1, 1);
        // otherwise dfs
        return mem[i][j] = reduce(dfs(i, j + 1));
    } else if (grid[i][j] == 'S') { // splitter
        vector<frac> v;

        // cout << "\n\n\n"
        //  << i << ' ' << j << endl;

        if (i > 1) {
            if (grid[i - 1][j] != 'v' && grid[i - 1][j] != '.') {
                v.push_back(dfs(i - 1, j));
                // cout << "^: " << dfs(i - 1, j).n << ' ' << dfs(i - 1, j).d << endl;
            }
        }
        if (i < N) {
            if (grid[i + 1][j] != '^' && grid[i + 1][j] != '.') {
                v.push_back(dfs(i + 1, j));
                // cout << "v: " << dfs(i + 1, j).n << ' ' << dfs(i + 1, j).d << endl;
            }
        }
        if (j > 1) {
            if (grid[i][j - 1] != '>' && grid[i][j - 1] != '.') {
                v.push_back(dfs(i, j - 1));
                // cout << "<: " << dfs(i, j - 1).n << ' ' << dfs(i, j - 1).d << endl;
            }
        }
        if (j < M) {
            if (grid[i][j + 1] != '<' && grid[i][j + 1] != '.') {
                v.push_back(dfs(i, j + 1));
                // cout << ">: " << dfs(i, j + 1).n << ' ' << dfs(i, j + 1).d << endl;
            }
        }
        if (v.empty())
            return mem[i][j] = frac(0, 1);
        else {
            int n = v.size();
            frac ans = reduce(mul(v[0], frac(1, n)));
            for (int i = 1; i < v.size(); i++) {
                ans = reduce(add(ans, mul(v[i], frac(1, n))));
            }
            return mem[i][j] = ans;
        }
        // return mem[i][j]= frac(0, 1);
    }
}
int main() {
    cin >> T;
    while (T--) {
        memset(mem, 0, sizeof(mem));
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++)
                cin >> grid[i][j];
        }
        frac bans = reduce(dfs(1, 1));
        cout << bans.n << ' ' << bans.d << endl;
        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= M; j++) {
        //         cout << mem[i][j].n << ' ';
        //     }
        //     cout << endl;
        // }
    }
}