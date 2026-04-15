#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    // avoid issues with getline after cin, consume the newline
    cin.ignore();
    for (int t = 0; t < T; t++) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        string result = "";
        int j = 0; // pointer for b

        // go thru each character in a
        for (int i = 0; i < A.size(); i++) {
            if (j < B.size() && A[i] == B[j]) {
                result += A[i];
                j++;
            } else {
                result += '#';
            }
        }
        cout << result << endl;
    }
    return 0;
}
