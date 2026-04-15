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
    int aLen = A.length(), bLen = B.length();
    int l = 0;
    string ans = "";
    for(int i = 0; i < bLen; i++) {
        while(l < aLen) {
            if(B[i] == A[l]) {
                ans += A[l];
                l++;
                break;
            } else {
                ans += '#';
            }
            l++;
        }
    }
    for(int i = l; i < aLen; i++) {
        ans += '#';
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