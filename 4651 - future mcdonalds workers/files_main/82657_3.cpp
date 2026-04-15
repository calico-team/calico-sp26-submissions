#include <bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;

string solve(string A, string B) {
    /*
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    */

    string ans; ans.reserve(A.size()); //make a copy of A to do work on
    int j = 0; //how many chars have been found (progress counter)

    for (char ch:A) { //for every char in A
        if (j<B.size()&&ch==B[j]) {ans.pb(ch); j++;}  //see if it matches the jth index of B which is tracking the chars of B so we can match it
        else {ans.pb('#');} //if it doesnt we can redact it and move on
    }
    return ans; //return redacted string

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
