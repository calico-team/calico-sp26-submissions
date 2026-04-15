#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        int j = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (j < B.size() && A[i] == B[j]) {
                j++;
            } else {
                A[i] = '#';
            }
        }
        cout << A << '\n';
    }
    return 0;
}
