#include <iostream>
#include <string>
using namespace std;

string solve(string A, string B) {
    int a = 0, b = 0;
    while (b < B.length()) {
        char ch = B[b];
        if (A[a] == ch) {
            a++;
            b++;
        }
        else {
            A[a] = '#';
            a++;
        }
    }

    while(a < A.length()) {
        A[a] = '#';
        a++;
    }

    return A;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}