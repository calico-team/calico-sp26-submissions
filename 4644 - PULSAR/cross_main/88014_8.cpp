#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val;
                if (i >= 1 && i <= n-2 && j >= 1 && j <= m-2) val = 2;
                else if (i == 0 && j >= 1 && j <= m-2) val = 0;
                else if (i == n-1 && j >= 1 && j <= m-2) val = 4;
                else if (j == 0 && i >= 1 && i <= n-2) val = 1;
                else if (j == m-1 && i >= 1 && i <= n-2) val = 3;
                else val = 0;

                cout << val;
                if (j != m-1) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
