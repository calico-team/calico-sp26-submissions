#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    /*
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    */
    int bt=0;
    string out=A;
    for (int i=0;i<A.length();i++)
    {
        if (A[i]==B[bt])
        {
            out[i]=A[i];
            bt++;
        }else
        {
            out[i]='#';
        }
    }
    cout<<out;
    // YOUR CODE HERE
    return "";
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