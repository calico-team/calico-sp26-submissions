#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> lshadow(n, vector<int>(n));
        vector<vector<int>> rshadow(n, vector<int>(n));

        for (int x = 0; x < n; x++) {
            string row;
            cin >> row;
            for (int y = 0; y < n; y++) {
                lshadow[x][y] = (row[y] == '#');
            }
        }

        for (int x = 0; x < n; x++) {
            string row;
            cin >> row;
            for (int y = 0; y < n; y++) {
                rshadow[x][y] = (row[y] == '#');
            }
        }

        vector<int> countl(n), countr(n);

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                countl[x] += lshadow[x][y];
                countr[x] += rshadow[x][y];
            }
        }

        long long maxans = 0, minans = 0;

        for (int x = 0; x < n; x++) {
            minans += max(countl[x], countr[x]);
            maxans += countl[x] * countr[x];
        }

        cout << maxans << " " << minans << endl;
    }
}