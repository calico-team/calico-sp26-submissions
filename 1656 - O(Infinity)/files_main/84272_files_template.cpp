#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    /*
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    */
    
    // YOUR CODE HERE

    int i, j = 0;
    for(i=0; i<A.length();i++){
        if (A[i] != B[j] || j == B.length()){
            A[i] = '#';
        }
        else {
            j++;
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