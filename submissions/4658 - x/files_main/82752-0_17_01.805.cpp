#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string A, B;
        cin >> A >> B;

        queue<char> q;

        for (char i : B) q.push(i);
        for (int j = 0; j < A.length(); j++) {
            if (!q.empty() && A[j] == q.front()) {
                q.pop();
            } 
            else {
                A[j] = '#';
            }
        }
        cout << A << "\n";
    }
    return 0;
}