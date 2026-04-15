#include <bits/stdc++.h>
using namespace std;

string solve(string A, string B) {
    string ans;
    int j = 0;
    for (int i = 0; i < A.length(); i++) {
        if (j < B.length() && A[i] == B[j]) {ans += A[i]; j++;}
        else ans += "#";
    }
    return ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
}