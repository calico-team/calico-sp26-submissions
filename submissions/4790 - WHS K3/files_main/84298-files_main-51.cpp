#include <bits/stdc++.h>
#include <string>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    /*
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    */
    int j = 0;
    std::string output = "";
    for (int i = 0; i < A.length(); i++) {
        if (j >= B.length() || A[i] != B[j]) {
            output += "#";
        } else {
            output += A[i];
            j++;
        }
    }
    return output;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}