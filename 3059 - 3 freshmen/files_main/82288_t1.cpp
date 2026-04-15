#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    int idx = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == B[idx]){
            idx++;
        }
        else{
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