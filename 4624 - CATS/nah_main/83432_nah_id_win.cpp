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

        bool win = true;
        for (int i = 0; i < n; i++) {
            if (i % k == 0 && i != 0) {
                p += r;
            }

            if (p >= e[i]) {
                p -= e[i];
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