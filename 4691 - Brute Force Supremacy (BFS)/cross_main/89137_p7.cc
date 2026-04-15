#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <set>

using namespace std;

typedef long long ll;

int ans[1001][1001];
bool found = false;
int N = -1, M = -1;


void print() {
 for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j];
            if (j < M - 1) cout << " ";
        }
        cout << endl;
    }
}
bool check(int i, int j) {
    vector<int> f(5, 0);
    f[ans[i][j]]++;
    f[ans[i - 1][j - 1]]++;
    f[ans[i - 1][j]]++;
    f[ans[i - 1][j + 1]]++;
    f[ans[i - 2][j]]++;
    for (int i = 0; i < 5; i++) {
        if (f[i] != 1) return false;
    }
    return true;
}

void rec(int i, int j) {
    //print();
    if (found) {
        return;
    }
    if (i == N) {
        found = true;
        print();
        return;
    }
    int ni = i;
    int nj = j + 1;
    if (j == M - 1) {
        nj = 0;
        ni++;
    }
    for (int t = 0; t < 5; t++) {
        if (j > 0 && t == ans[i][j - 1]) continue;
        if (i > 0 && t == ans[i - 1][j]) continue;
        ans[i][j] = t;
        if (i >= 2 && j > 0 && j < M - 1 && !check(i, j)) continue;
        rec(ni, nj);
    }

}

void solve(int n, int m) {
    rec(0, 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans[i][j] = -1;
    found = false;
    N = m;
    M = m;
    solve(n, m);
  }
}
