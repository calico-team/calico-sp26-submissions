#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string x, string y) {
    /*
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    */
    
    // YOUR CODE HERE
    
    
   string r= "";
   
   int j = 0;
   
   for(int i = 0; i < x.size(); i++){
	   
	   if(j < y.size() && x[i]==y[j]){
		   
		   r += x[i];
		   j++;
		   }else
		         r+='#';
		         
	   
	   }
    
    
    return r;
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
