#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int P, A, B;
        cin >> P >> A >> B;

        vector<pair<int,int>> cells;

        map<pair<int,int>, char> g;

        int r = 0, c = 0;

        g[{r,c}] = 'v';

        int cur_r = r, cur_c = c;

        for (int i = 0; i < A; i++) {
            g[{cur_r, cur_c}] = 'S';
            g[{cur_r, cur_c+1}] = '>';
            g[{cur_r+1, cur_c}] = 'v';
            g[{cur_r+1, cur_c+2}] = 'X';

            cur_c += 1;
            cur_r += 1;
        }

        for (int i = 0; i < B; i++) {
            g[{cur_r, cur_c}] = 'S';
            g[{cur_r, cur_c+1}] = '>';
            g[{cur_r+1, cur_c}] = 'v';
            g[{cur_r+1, cur_c-1}] = '<';

            cur_c += 1;
            cur_r += 1;
        }

        vector<pair<int,int>> end_nodes;
        for (int i = 0; i < P; i++) {
            g[{cur_r, cur_c+i}] = 'v';
            end_nodes.push_back({cur_r, cur_c+i});
        }
        for (int i = P; i < P + 10; i++) {
            g[{cur_r, cur_c+i}] = 'X';
        }

        int min_r = INT_MAX, max_r = INT_MIN;
        int min_c = INT_MAX, max_c = INT_MIN;

        for (auto &it : g) {
            min_r = min(min_r, it.first.first);
            max_r = max(max_r, it.first.first);
            min_c = min(min_c, it.first.second);
            max_c = max(max_c, it.first.second);
        }

        int H = max_r - min_r + 1;
        int W = max_c - min_c + 1;

        vector<string> out(H, string(W, '.'));

        for (auto &it : g) {
            int rr = it.first.first - min_r;
            int cc = it.first.second - min_c;
            out[rr][cc] = it.second;
        }

        cout << H << " " << W << "\n";
        for (auto &row : out) cout << row << "\n";
    }

    return 0;
}
// 6 10 
// v.>>>>v.^. 
// v.^...v.^. 
// >>S>S>>>S. 
// ..X.v...v. 
// ....>>>>X. 
// .......... 
// 5 9 
// >>>v...X. 
// ...v...S> 
// ..vS>>v^. 
// <<S...>^. 
// ..>>>>^.. 
// 3 5 
// >v..X 
// vS>S^ 
// >>>>v