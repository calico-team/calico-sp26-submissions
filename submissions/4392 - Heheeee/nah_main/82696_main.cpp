#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, p, r, k;
        cin >> n >> p >> r >> k;

        vector<int> curse(n);
        for (int i = 0; i < n; ++i) {
            cin >> curse[i];
        }

        bool gojosolosallthespecialgradesanddoesntgetsealed = true;
        for (int i = 0; i < n; ++i) {
            p -= curse[i];
            if (p < 0) {
                cout << "nah i'd lose\n";
                gojosolosallthespecialgradesanddoesntgetsealed = false;
                break;
            }
            if ((i + 1) % k == 0) {
                p += r;
            }
        }

        if (gojosolosallthespecialgradesanddoesntgetsealed) {
            cout << "nah i'd win\n";
        }
    }

    return 0;
}