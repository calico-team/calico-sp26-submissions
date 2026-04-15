#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    /*
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    */
    int B_index = 0;
    for (int i = 0; i < A.size(); i++) {
        // if (B_index == B.size()){
        //     return A;
        // }
        if (A[i] == B[B_index]){
            B_index++;
        }
        else {
            A[i] = '#';
        }
    }

    return A;
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