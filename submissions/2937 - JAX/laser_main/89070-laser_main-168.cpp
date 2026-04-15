#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int T;
int K, N, M, P, Q;
int gcd(int n1, int n2) {
    if (n1 == 0)
        return n2;
    return gcd(n2 % n1, n1);
}
vector<pair<int, int>> ast;
int main() {
    // freopen("4.out", "w", stdout);
    cin >> T;
    while (T--) {
        ast.clear();
        cin >> K >> N >> M >> P >> Q;
        int g = gcd(P, Q);
        P /= g;
        Q /= g;
        for (int i = 0; i < K; i++) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            ast.push_back(p);
        }
        int x = ast[0].first, y = ast[0].second;
        // cout << x << ' ' << y << endl;
        while (1) {
            x += Q;
            y += P;
            x %= N;
            y %= M;
            // cout << x << ' ' << y << endl;
            bool f = 0;
            for (int i = 0; i < K; i++) {
                if (ast[i].first == x && ast[i].second == y) {
                    f = 1;
                    cout << i << endl;
                    break;
                }
            }
            if (f)
                break;
        }
        // cout << endl;
    }
}