#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    int i = 0; 
    int j =0;
    while(i < A.length()){
        if(A[i] == B[j]) {
            i++;
            j++;
        }
        else {
            A[i] = '#';
            i++;
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