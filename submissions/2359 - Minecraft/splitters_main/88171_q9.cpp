#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll calcGCD(ll x, ll y) {
    x = abs(x); y = abs(y);
    while (y) {
        ll tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}
int128 bigGCD(int128 x, int128 y) {
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    while (y) {
        int128 tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}
struct Fraction {
    ll num, den;
    Fraction(ll n = 0, ll d = 1) : num(n), den(d) { normalize(); }
    void normalize() {
        if (den == 0) { num = 0; den = 1; return; }
        if (den < 0) { num = -num; den = -den; }
        ll g = calcGCD(num, den);
        num /= g;
        den /= g;
    }
};
Fraction addFrac(Fraction x, Fraction y) {
    int128 newNum = (int128)x.num * y.den + (int128)y.num * x.den;
    int128 newDen = (int128)x.den * y.den;
    int128 gg = bigGCD(newNum, newDen);
    newNum /= gg;
    newDen /= gg;
    return Fraction((ll)newNum, (ll)newDen);
}
Fraction splitBy(Fraction x, ll cnt) {
    int128 newNum = (int128)x.num;
    int128 newDen = (int128)x.den * cnt;
    int128 gg = bigGCD(newNum, newDen);
    newNum /= gg;
    newDen /= gg;
    return Fraction((ll)newNum, (ll)newDen);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testCases;
    cin >> testCases;
    int deltaRow[4] = {-1, 0, 1, 0};
    int deltaCol[4] = {0, 1, 0, -1};
    char dirSymbols[4] = {'^', '>', 'v', '<'};
    auto getDirIndex = [&](char ch) -> int {
        if (ch == '^') return 0;
        if (ch == '>') return 1;
        if (ch == 'v') return 2;
        if (ch == '<') return 3;
        return -1;
    };
    for (int cas = 0; cas < testCases; cas++) {
        int rowCount, colCount;
        cin >> rowCount >> colCount;
        vector<string> factoryMap(rowCount);
        for (int r = 0; r < rowCount; r++) cin >> factoryMap[r];
        vector<vector<Fraction>> probabilityCache(rowCount, vector<Fraction>(colCount, Fraction(-1, 1)));
        auto calculateFraction = [&](auto&& self, int r, int c) -> Fraction {
            if (probabilityCache[r][c].num != -1) return probabilityCache[r][c];
            char tile = factoryMap[r][c];
            Fraction currentResult(0, 1);
            if (tile == 'x' || tile == '.') {
                currentResult = Fraction(0, 1);
            } else if (getDirIndex(tile) != -1) {
                int d = getDirIndex(tile);
                int nr = r + deltaRow[d];
                int nc = c + deltaCol[d];
                if (nr < 0 || nr >= rowCount || nc < 0 || nc >= colCount) {
                    currentResult = Fraction(1, 1);
                } else {
                    currentResult = self(self, nr, nc);
                }
            } else if (tile == 'S') {
                vector<pair<int, int>> validNext;
                for (int d = 0; d < 4; d++) {
                    int nr = r + deltaRow[d];
                    int nc = c + deltaCol[d];
                    if (nr < 0 || nr >= rowCount || nc < 0 || nc >= colCount) continue;
                    char nextTile = factoryMap[nr][nc];
                    bool isValid = false;
                    if (nextTile == 'x') isValid = true;
                    else if (getDirIndex(nextTile) != -1) {
                        int backDir = (d + 2) % 4;
                        if (nextTile != dirSymbols[backDir]) isValid = true;
                    }
                    if (isValid) validNext.emplace_back(nr, nc);
                }
                int neighborCount = validNext.size();
                Fraction totalSum(0, 1);
                for (auto [nr, nc] : validNext) {
                    Fraction nextFrac = self(self, nr, nc);
                    totalSum = addFrac(totalSum, nextFrac);
                }
                currentResult = splitBy(totalSum, neighborCount);
            }
            probabilityCache[r][c] = currentResult;
            return currentResult;
        };
        Fraction finalAnswer = calculateFraction(calculateFraction, 0, 0);
        if (finalAnswer.num == 0) {
            cout << "0 1\n";
        } else {
            cout << finalAnswer.num << " " << finalAnswer.den << "\n";
        }
    }
    return 0;
}