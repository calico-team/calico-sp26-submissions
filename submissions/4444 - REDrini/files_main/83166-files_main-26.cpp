#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        int pointer = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (pointer < B.size() && A[i] == B[pointer]) {
                ++pointer;
                continue;
            }
            A[i] = '#';
        }
        cout << A << '\n';
    }
}