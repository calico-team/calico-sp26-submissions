#include <iostream>
using namespace std;
int t, e[10005];
int main()
{
    cin >> t;
    while (t--) {
        int n, p, r, k; cin >> n >> p >> r >> k;
        bool b = true, c = true;
        for (int i = 1; i <= n; i++) {
            cin >> e[i];
            p -= e[i];
            if (b && i - 1 >= k) {
                b=false;
                p+=r;
            }
            if (p < 0 && (i - 1 < k || p + r < 0)) {
                cout << "nah i'd lose\n";
                c = false;
                break;
            }
        }
        if (c) {
            cout << "nah i'd win\n";
        }
    }
    return 0;
}