#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


string solve(string A, string b) {
    int size=A.size(); 
    string updated_str=A;
    int j=0;

    for(int i=0;i<size;i++){
        if(j<b.size() && A[i]==b[j]){
            j++;
        }else{
            updated_str[i]='#';
        }
                
        }
        return updated_str;
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