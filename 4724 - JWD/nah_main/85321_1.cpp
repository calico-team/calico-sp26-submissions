#include <iostream>
using namespace std;
int t, e[10005];
int main()
{
    cin >> t;
    while (t--) {
        int n, p = 0, r, k; cin >> n >> p >> r >> k;
        bool c = true;
		int k1 = k;
        for (int i = 1; i <= n; i++) {
            cin >> e[i];
            p -= e[i];
			k1--;
            if (k1 == 0 && p >= 0) {
				k1 = k;
                p+=r;
            }
            if (p < 0) {
                c = false;
            }
        }
        if (c) {
            cout << "nah i'd win\n";
        } else {
			cout << "nah i'd lose\n";
		}
    }
    return 0;
}