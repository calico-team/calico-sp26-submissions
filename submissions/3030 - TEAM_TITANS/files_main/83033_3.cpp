#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t ; 
    while(t--){
        string a,b; 
        cin>>a>>b; 
        int move=0; 
        for (int i =0 ; i<a.size();i++){
            if (move < b.size()&&a[i]==b[move]) {
            move++;
        } else {
            a[i] = '#'; 
        }
            
        }
        cout<<a<<"\n" ;
        
    }
}