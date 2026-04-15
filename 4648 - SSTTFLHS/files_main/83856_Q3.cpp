#include <iostream>
#include <string>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        string A, B;
        cin >> A >> B;

        string ans;
        int b = 0;

        for (char ch : A) {
            if (b < B.length() && ch == B[b]) {
                ans += ch;
                b++;
            } else {
                ans += '#';
            }
        }

        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}