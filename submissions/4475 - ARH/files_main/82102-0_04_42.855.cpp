#include <iostream>
#include <string>

using namespace std;

string solve(const string& A, const string& B) {
    string answer = A;
    int j = 0;

    for (int i = 0; i < (int)A.size(); i++) {
        if (j < (int)B.size() && A[i] == B[j]) {
            j++;
        } else {
            answer[i] = '#';
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string A, B;
        cin >> A >> B;
        cout << solve(A, B) << "\n";
    }

    return 0;
}
