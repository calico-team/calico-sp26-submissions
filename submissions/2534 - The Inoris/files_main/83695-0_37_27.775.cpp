#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    
    int Jp=0;


    string Ans="";
    for(int i=0;i<A.length();i++)
    {
        if(A[i]==B[Jp]) 
        {
            Ans+=A[i];
            Jp++;
        }else{
            Ans+="#";
        }
    }


    return Ans;
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