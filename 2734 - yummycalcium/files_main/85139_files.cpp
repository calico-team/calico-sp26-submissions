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
    string ans = "";
    int ind = 0;
    for(int i = 0; i < A.length(); i++){
        if(ind > B.length()){
            ans += "#";
        }
        else{
            if(A[i] == B[ind]){
                ans += A[i];
                ind++;
            }
            else{
                ans += "#";
            }
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
