#include <bits/stdc++.h>
using namespace std; 
int main(){
    int t; cin>>t ; 

    while(t--){
        int l,w,e,r;
        cin>>l>>w>>e>>r ;
        int total ;
        total = 2*(l+w)*r;


        cout<<ceil(e/total)<<"\n";

    }
}