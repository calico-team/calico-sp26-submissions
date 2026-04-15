#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    int j = 0;
    int n = B.size();

    for (int i = 0; i < (int)A.size(); i++) {
        if (j < n && A[i] == B[j]) {
            j++;
        } else {
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
