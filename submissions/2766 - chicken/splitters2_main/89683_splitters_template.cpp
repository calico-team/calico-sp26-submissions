#include <bits/stdc++.h>
using namespace std;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
struct fraction {
    long long p;
    long long q;
};

long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

fraction normalize(fraction f) {
    if (f.p == 0) {
        f.q = 1;
        return f;
    }
    if (f.q < 0) {
        f.p = -f.p;
        f.q = -f.q;
    }
    long long g = gcd(f.p, f.q);
    f.p = f.p / g;
    f.q = f.q / g;
    return f;
}

fraction makeFraction(long long p, long long q) {
    fraction f;
    f.p = p;
    f.q = q;
    return normalize(f);
}

fraction addFraction(fraction a, fraction b) {
    fraction c;
    c.p = a.p * b.q + b.p * a.q;
    c.q = a.q * b.q;
    return normalize(c);
}

fraction divFraction(fraction a, long long k) {
    a.q = a.q * k;
    return normalize(a);
}


fraction dp [15][15]; bool availablilty [15][15];

/**
 * Simulate the factory and return the final output as the fraction P / Q.
 *
 * N: number of rows in the factory grid
 * M: number of columns in the factory grid
 * factory: vector of N strings of length M, each character one of '^<>vSX.'
 */



pair<long long, long long> solve(int N, int M, vector<string>& factory) {
    // YOUR CODE HERE
    // initialize
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            availablilty[i][j] = false;
        }   
    }
    availablilty[0][0] = true;
    queue <pair <int, int>> q;
    q.push(make_pair(0, 0));
    while (q.empty() == false)
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        char c = factory[i][j];
        if (c == 'S' || c == 's') {
            for (int d = 0; d < 4; d++) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                char nc = factory[ni][nj];
                if (nc == '.') continue;
                if (nc == '<' && ni == i && nj == j - 1) continue;
                if (nc == '>' && ni == i && nj == j + 1) continue;
                if (nc == '^' && ni == i - 1 && nj == j) continue;
                if (nc == 'v' && ni == i + 1 && nj == j) continue;
                if (availablilty[ni][nj] == false) {
                    availablilty[ni][nj] = true;
                    q.push(make_pair(ni, nj));
                }
            }
        }

        else if (c == '<' || c == '>' || c == '^' || c == 'v') {
            int ni = i;
            int nj = j;
            if (c == '<') nj = j - 1;
            if (c == '>') nj = j + 1;
            if (c == '^') ni = i - 1;
            if (c == 'v') ni = i + 1;
            if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
            if (factory[ni][nj] == '.') continue;
            if (availablilty[ni][nj] == false) {
                availablilty[ni][nj] = true;
                q.push(make_pair(ni, nj));
            }
        }
    }

    int indegree[15][15];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            indegree[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (availablilty[i][j] == false) continue;
            char c = factory[i][j];
            if (c == 'S' || c == 's') {
                for (int d = 0; d < 4; d++) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                    char nc = factory[ni][nj];
                    if (nc == '.') continue;
                    if (nc == '<' && ni == i && nj == j - 1) continue;
                    if (nc == '>' && ni == i && nj == j + 1) continue;
                    if (nc == '^' && ni == i - 1 && nj == j) continue;
                    if (nc == 'v' && ni == i + 1 && nj == j) continue;
                    if (availablilty[ni][nj]) {
                        indegree[ni][nj] = indegree[ni][nj] + 1;
                    }
                }
            }
            else if (c == '<' || c == '>' || c == '^' || c == 'v') {
                int ni = i;
                int nj = j;
                if (c == '<') nj = j - 1;
                if (c == '>') nj = j + 1;
                if (c == '^') ni = i - 1;
                if (c == 'v') ni = i + 1;
                if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                if (factory[ni][nj] == '.') continue;
                if (availablilty[ni][nj]) {
                    indegree[ni][nj] = indegree[ni][nj] + 1;
                }
            }
        }
    }

    fraction prob[15][15];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            prob[i][j] = makeFraction(0, 1);
        }
    }
    prob[0][0] = makeFraction(1, 1);

    queue<pair<int,int>> q2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (availablilty[i][j] && indegree[i][j] == 0) {
                q2.push(make_pair(i, j));
            }
        }
    }

    fraction collected = makeFraction(0, 1);
    while (q2.empty() == false) {
        int i = q2.front().first;
        int j = q2.front().second;
        q2.pop();
        fraction cur = prob[i][j];
        char c = factory[i][j];

        if (c == 'x' || c == 'X') {
            continue;
        }

        if (c == '<' || c == '>' || c == '^' || c == 'v') {
            int ni = i;
            int nj = j;
            if (c == '<') nj = j - 1;
            if (c == '>') nj = j + 1;
            if (c == '^') ni = i - 1;
            if (c == 'v') ni = i + 1;
            if (ni < 0 || ni >= N || nj < 0 || nj >= M) {
                collected = addFraction(collected, cur);
                continue;
            }
            if (factory[ni][nj] == '.') continue;
            if (availablilty[ni][nj]) {
                prob[ni][nj] = addFraction(prob[ni][nj], cur);
                indegree[ni][nj] = indegree[ni][nj] - 1;
                if (indegree[ni][nj] == 0) {
                    q2.push(make_pair(ni, nj));
                }
            }
            continue;
        }

        if (c == 'S' || c == 's') {
            int count = 0;
            for (int d = 0; d < 4; d++) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                char nc = factory[ni][nj];
                if (nc == '.') continue;
                if (nc == '<' && ni == i && nj == j - 1) continue;
                if (nc == '>' && ni == i && nj == j + 1) continue;
                if (nc == '^' && ni == i - 1 && nj == j) continue;
                if (nc == 'v' && ni == i + 1 && nj == j) continue;
                if (availablilty[ni][nj]) {
                    count = count + 1;
                }
            }
            if (count == 0) continue;
            fraction share = divFraction(cur, count);
            for (int d = 0; d < 4; d++) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                char nc = factory[ni][nj];
                if (nc == '.') continue;
                if (nc == '<' && ni == i && nj == j - 1) continue;
                if (nc == '>' && ni == i && nj == j + 1) continue;
                if (nc == '^' && ni == i - 1 && nj == j) continue;
                if (nc == 'v' && ni == i + 1 && nj == j) continue;
                if (availablilty[ni][nj]) {
                    prob[ni][nj] = addFraction(prob[ni][nj], share);
                    indegree[ni][nj] = indegree[ni][nj] - 1;
                    if (indegree[ni][nj] == 0) {
                        q2.push(make_pair(ni, nj));
                    }
                }
            }
            continue;
        }
    }

    collected = normalize(collected);
    return make_pair(collected.p, collected.q);
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
