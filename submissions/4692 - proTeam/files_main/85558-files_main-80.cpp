#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;

        int index = 0;
        for (int i = 0; i < (int)A.size(); i++) {
            if (index < (int)B.size() && A[i] == B[index]) {
                index++;
            } else {
                A[i] = '#';
            }
        }

        cout << A << endl;
    }

    return 0;
}
