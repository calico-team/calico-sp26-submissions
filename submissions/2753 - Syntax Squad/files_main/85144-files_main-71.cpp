#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    int counter=0;
    
    for (int i=0; i<A.size(); i++) {
        if (counter<B.size() && A[i]==B[counter]) {
            counter++;
        } else {
            A[i]='#';
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