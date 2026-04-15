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
        string a, b;
        cin >> a >> b;

        int j = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[j]) {
                a[i] = '#';
            }
            else {
                ++j;
            }
        }

        cout << a << '\n';
    }

    return 0;
}