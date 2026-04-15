#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        string result;
        int j = 0;
        for (int i = 0; i < A.size(); i++) {
            char c = A[i];
            if (j < B.size() && c == B[j]) {
                result += c;
                j++;
            } else {
                result += '#';
            }
        }
        cout << result << endl;
    }
    return 0;
}