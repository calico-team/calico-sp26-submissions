#include <bits/stdc++.h>
using namespace std;

string censor_this_please(string A, string B) {
    int j = 0;
    for (int i = 0; i < (int)A.size(); i++) {
        if (j < (int)B.size() && A[i] == B[j]) {
            j++;
        } else {
            A[i] = '#';
        }
    }
    return A;
}

void read_your_input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        cout << censor_this_please(A, B) << '\n';
    }
}

int main() {
    read_your_input();
    return 0;
}