#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n = 400, m = 400;
int a[400][400];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        xg += 200, yg += 200, xm += 200, ym += 200;
        a[xg][yg] = 1;
        a[xm][ym] = 2;
        for (int i = 1; i < 500; i++) {
            if (i % 2 == 0) {
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (a[x][y] == 1) {
                            for (int j = 0; j < 4; j++) {
                                if (a[x + dx[j]][y + dy[j]] == 0) {
                                    a[x + dx[j]][y + dy[j]] = 3;
                                }
                            }
                        }
                    }
                }
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (a[x][y] == 3) {
                            a[x][y] = 1;
                        }
                    }
                }
            }
            if (i % 7 == 0) {
                bool found = false;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (a[x][y] == 2) {
                            for (int j = 0; j < 4; j++) {
                                if (a[x + dx[j]][y + dy[j]] == 0) {
                                    a[x + dx[j]][y + dy[j]] = 3;
                                    found = true;
                                }
                            }
                        }
                    }
                }
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (a[x][y] == 3) {
                            a[x][y] = 2;
                        }
                    }
                }
                if (!found) break;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 2) count++;
            }
        }
        cout << count << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = 0;
            }
        }
    }
}