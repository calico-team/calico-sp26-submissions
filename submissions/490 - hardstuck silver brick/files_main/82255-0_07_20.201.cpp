#include <iostream>
#include <string>
using namespace std;

string censor(string A, string B) {
    string res;
    int j = 0;
    for (char c : A) {
        if (j < B.size() && c == B[j]) {
            res += c;
            j++;
        }
        else {
            res += '#';
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        cout << censor(A, B) << endl;
    }
    return 0;
}