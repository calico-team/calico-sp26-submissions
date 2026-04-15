#include <iostream>
#include <vector>
#define FASTIO std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
using namespace std;

int main() { FASTIO;
    int t; // number of test cases
    int n, p, r, k; // # of curses, starting power, amount of power restored by curse, # of curses must defeat before curse
    vector<int> e; // power levels of each curse

    cin >> t;
    while (t--) {
        cin >> n >> p >> r >> k;
        e.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> e[i];
        }

        int curr_curses = 0;
        bool win = true;
        for (int i = 0; i < n; i++) {
            if (p >= e[i]) {
                p -= e[i];
                curr_curses++;
                continue;
            }

            if (curr_curses >= k && p + r >= e[i]) {
                p += r - e[i];
                curr_curses -= (k - 1);
            } else {
                win = false;
                break;
            }
        }

        if (win) {
            cout << "nah i'd win" << endl;
        } else {
            cout << "nah i'd lose" << endl;
        }
    }
    return 0;
}