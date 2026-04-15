// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

string solve(string A, string B) {
    /*
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    */
    
    // YOUR CODE HERE

    int on = 0;
    string ans = "";

    for (int i = 0; i < A.size(); i++) {
        if (A[i] == B[on]) {
            ans += B[on];
            on++;
        } else {
            ans += "#";
        }
    }

    return ans;
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