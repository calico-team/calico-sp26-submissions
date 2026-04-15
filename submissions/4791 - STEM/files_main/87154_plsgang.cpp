#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    /*
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    */
    vector<int> hey;
    string x = A;
    string y = B;
    int found = 0;
    
    
    
    // YOUR CODE HERE
    for (int i = 0; i < B.size(); i++){
        int position = A.find(B[i],found);
        hey.push_back(position);
        
        found = position + 1;
    }
    
    for (int i = 0; i < A.size(); i++){
        A[i] = '#';
    }
    for (int i = 0; i < A.size(); i++){
         for (int j = 0; j < hey.size(); j++){
             if (hey[j] == i){
                A[i] = x[i];
             }
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