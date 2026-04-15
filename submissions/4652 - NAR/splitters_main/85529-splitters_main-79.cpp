#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <math.h>
#include <queue>
#include <iomanip>
#include <map>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <cstdint>
#include <assert.h>
#include <limits.h>
#include <unordered_map>
#include <memory>
#include <istream>
#include <deque>

using ll = long long;

using namespace std;

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

pair<ll, ll> addFraction(pair<ll, ll> a, pair<ll, ll> b) {
    pair<ll, ll> ans;
    ll den = (a.second * b.second) / gcd(a.second, b.second);
    ll num = (a.first) * (den / a.second) + (b.first) * (den / b.second);
    ll fac = gcd(num, den);
    den = den / fac;
    num = num / fac;
    return make_pair(num, den);
}

int main() {
    //ifstream cin("a.in");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> f(N);
        for (int i = 0; i < N; i++) {
            cin >> f[i];
        }
        int x = -1, y;
        for (int i = 0; i < M; i++) {
            if (f[0][i] == '^') {
                x = 0;
                y = i;
            }
        }
        for (int i = 0; i < M; i++) {
            if (f[N - 1][i] == 'v') {
                x = N - 1;
                y = i;
            }
        }
        for (int i = 0; i < N; i++) {
            if (f[i][0] == '<') {
                x = i;
                y = 0;
            }
        }
        for (int i = 0; i < N; i++) {
            if (f[i][M - 1] == '>') {
                x = i;
                y = M - 1;
            }
        }
        if (x == -1) {
            cout << "0 1" << endl;
            continue;
        }
        vector<vector<int>> pars(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (f[i][j] == 'S') {
                    pars[i][j] = 1;
                    continue;
                }
                if (i > 0) {
                    if (f[i - 1][j] == 'v' || f[i - 1][j] == 'S') {
                        if (f[i][j] != '^') {
                            pars[i][j]++;
                        }
                    }
                }
                if (i < N - 1) {
                    if (f[i + 1][j] == '^' || f[i + 1][j] == 'S') {
                        if (f[i][j] != 'v') {
                            pars[i][j]++;
                        }
                    }
                }
                if (j > 0) {
                    if (f[i][j - 1] == '>' || f[i][j - 1] == 'S') {
                        if (f[i][j] != '<') {
                            pars[i][j]++;
                        }
                    }
                }
                if (j < M - 1) {
                    if (f[i][j + 1] == '<' || f[i][j + 1] == 'S') {
                        if (f[i][j] != '>') {
                            pars[i][j]++;
                        }
                    }
                }
            }
        }
        vector<vector<pair<ll, ll>>> at(N, vector<pair<ll,ll>>(M, make_pair(0, 1)));
        queue<pair<pair<int, int>, pair<ll, ll>>> Q;

        pars[0][0] = 1;
        Q.push(make_pair(make_pair(0, 0), make_pair(1, 1)));
        pair<ll, ll> ans(0, 1);
        while (!Q.empty()) {
            int curx = Q.front().first.first, cury = Q.front().first.second;
            pair<ll, ll> prob = Q.front().second;
            Q.pop();
            if (curx < 0 || curx == N || cury < 0 || cury == M) {
                ans = addFraction(ans, prob);
                continue;
            }
            if (pars[curx][cury] == 0 || f[curx][cury] == 'X') {
                continue;
            }
            pars[curx][cury]--; 
            at[curx][cury] = addFraction(at[curx][cury], prob);
            if (pars[curx][cury] > 0) {
                continue;
            }
            prob = at[curx][cury];
            if (f[curx][cury] == 'S') {
                int num = 4;
                if (curx > 0) {
                    if (f[curx - 1][cury] == '.') {
                        num--;
                    }
                }
                if (curx < N - 1) {
                    if (f[curx + 1][cury] == '.') {
                        num--;
                    }
                }
                if (cury > 0) {
                    if (f[curx][cury - 1] == '.') {
                        num--;
                    }
                }
                if (cury < M - 1) {
                    if (f[curx][cury + 1] == '.') {
                        num--;
                    }
                }
                num--;
                prob.second *= num;
                Q.push(make_pair(make_pair(curx - 1, cury), prob));
                Q.push(make_pair(make_pair(curx + 1, cury), prob));
                Q.push(make_pair(make_pair(curx, cury - 1), prob));
                Q.push(make_pair(make_pair(curx, cury + 1), prob));
            }
            else if (f[curx][cury] == '^') {
                Q.push(make_pair(make_pair(curx - 1, cury), prob));
            }
            else if (f[curx][cury] == '>') {
                Q.push(make_pair(make_pair(curx, cury + 1), prob));
            }
            else if (f[curx][cury] == 'v') {
                Q.push(make_pair(make_pair(curx + 1, cury), prob));
            }
            else {
                Q.push(make_pair(make_pair(curx, cury - 1), prob));
            }
        }
        cout << ans.first << " " << ans.second << endl;
    }
}