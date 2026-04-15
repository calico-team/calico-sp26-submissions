#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    if (!(T >= 1 && T <= 100)) {
        cout << "T is greater than or equal to 1 and less than or equal to 100.";
        return -1;
    }
    while (T--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        if (!(N >= 1 && N <= pow(10, 4))) {
            cout << "N is greater than or equal to 1 and less than or equal to 10000.";
            return -1;
        }
        if (!(P >= 1 && P <= pow(10, 5))) {
            cout << "P is greater than or equal to 1 and less than or equal to 100000.";
            return -1;
        }
        if (!(R >= 1 && R <= pow(10, 4))) {
            cout << "R is greater than or equal to 1 and less than or equal to 10000.";
            return -1;
        }
        if (!(K >= 1 && K <= pow(10, 4))) {
            cout << "K is greater than or equal to 1 and less than or equal to 10000.";
            return -1;
        }
        vector<int> E(N);
        for (int& x : E) {
            cin >> x;
            if (!(x >= 1 && x <= pow(10, 4))) {
                cout << "x is greater than or equal to 1 and less than or equal to 10000.";
                return -1;
            }
        }

        long long cur = P;
        int cnt = 0, heal = 0;
        bool ok = 1;

        for (int e : E) {
            cur -= e;
            cnt++;

            if (cur < 0 && heal > 0) {
                cur += R;
                heal--;
            }

            if (cur < 0) {
                ok = 0;
                break;
            }

            if (cnt % K == 0) heal++;
        }

        cout << (ok ? "nah i'd win" : "nah i'd lose") << endl;
    }
    return 0;
}