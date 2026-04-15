#include <bits/stdc++.h>
using namespace std;

/**
 * Simulate the factory and return the final output as the fraction P / Q.
 *
 * N: number of rows in the factory grid
 * M: number of columns in the factory grid
 * factory: vector of N strings of length M, each character one of '^<>vSX.'
 */

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

pair<long long, long long> numDenDim(int N, vector<pair<long long, long long>> numDens) {
    long long num = 1;
    long long den = 1;
    for (int i = 0; i < N; i++) {
        num *= numDens[i].first;
        den *= numDens[i].second;
    }
    long long a = gcd(num, den);

    num /= a;
    den /= a;

    return { num, den };
}

pair<long long, long long> recursiveSplitFollow(int x, int y, int N, int M, vector<string>& factory) {
    char currentChar = factory[y][x];
    while (currentChar != 'S') {
        if (currentChar == '^') {
            y++;
            if (y >= N) {
                return { 1, 1 };
            }
        }
        if (currentChar == '>') {
            x++;
            if (x >= M) {
                return { 1, 1 };
            }
        }
        if (currentChar == '<') {
            x--;
            if (x < 0) {
                return { 1, 1 };
            }
        }
        if (currentChar == 'v') {
            y--;
            if (y < 0) {
                return { 1, 1 };
            }
        }
        currentChar = factory[y][x];
    }
    bool l = false, r = false, u = false, d = false;
    if (x > 0) {
        if (factory[y][x - 1] != '.' && factory[y][x - 1] != '>') {
            l = true;
        }
    }
    if (x < M - 1) {
        if (factory[y][x + 1] != '.' && factory[y][x + 1] != '<') {
            r = true;
        }
    }
    if (y > 0) {
        if (factory[y - 1][x] != '.' && factory[y - 1][x] != '^') {
            d = true;
        }
    }
    if (y < N - 1) {
        if (factory[y + 1][x] != '.' && factory[y + 1][x] != 'v') {
            u = true;
        }
    }
    int count = (l ? 1 : 0) + (r ? 1 : 0) + (u ? 1 : 0) + (d ? 1 : 0);

    vector<pair<long long, long long>> numDens(count+1);

    int i = 1;

    numDens[0] = { 1, count };

    if (l) {
        numDens[i++] = recursiveSplitFollow(x - 1, y, N, M, factory);
    }
    if (r) {
        numDens[i++] = recursiveSplitFollow(x + 1, y, N, M, factory);
    }
    if (d) {
        numDens[i++] = recursiveSplitFollow(x, y - 1, N, M, factory);
    }
    if (u) {
        numDens[i++] = recursiveSplitFollow(x, y + 1, N, M, factory);
    }

    return numDenDim(count+1, numDens);
}

pair<long long, long long> solve(int N, int M, vector<string>& factory) {

    return recursiveSplitFollow(0, 0, N, M, factory);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> factory(N);
        for (int i = 0; i < N; i++) cin >> factory[i];
        auto [P, Q] = solve(N, M, factory);
        cout << P << " " << Q << "\n";
    }
    return 0;
}
