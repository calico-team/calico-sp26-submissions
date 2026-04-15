#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    int j = 0;
    string redact = "";
    for (char i : A){
        if (i == B[j]){
            redact += i;
            j++;
        }else{
            redact += '#';
        }
    }
    return redact;
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