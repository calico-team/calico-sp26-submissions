#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long P, A, B;
        cin >> P >> A >> B;

        long long total = 1;
        for (int i = 0; i < A; i++) total *= 2;
        for (int i = 0; i < B; i++) total *= 3;

        int width = (int)total;
        int height = (int)(A + B + 2);

        vector<string> grid(height, string(width, '.'));

        vector<int> curr = {width / 2};

        int row = 0;

        for (int i = 0; i < A; i++) {
            vector<int> next;
            for (int x : curr) {
                grid[row][x] = 'S';

                int left = x - 1;
                int right = x + 1;

                grid[row][left] = 'v';
                grid[row][right] = 'v';

                next.push_back(left);
                next.push_back(right);
            }
            curr = next;
            row++;
        }

        for (int i = 0; i < B; i++) {
            vector<int> next;
            for (int x : curr) {
                grid[row][x] = 'S';

                int l = x - 1;
                int m = x;
                int r = x + 1;

                grid[row][l] = 'v';
                grid[row][m] = 'v';
                grid[row][r] = 'v';

                next.push_back(l);
                next.push_back(m);
                next.push_back(r);
            }
            curr = next;
            row++;
        }

        for (int i = 0; i < (int)curr.size(); i++) {
            int x = curr[i];
            if (i < P) {
                grid[row][x] = 'v';
            } else {
                grid[row][x] = 'X'; 
            }
        }

        cout << height << " " << width << endl;
        for (auto &r : grid) {
            cout << r << endl;
        }
    }

    return 0;
}