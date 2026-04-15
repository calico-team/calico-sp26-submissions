#include <bits/stdc++.h>
using namespace std;
void solve() {
    int m,n;cin>>m>>n; 
    for (int r = 0; r < n;r++) {
        for (int c=0;c<m;c++) {
            if (c==m-1){
                cout<<(r+2*c)%5<<" " ; 
            }
            else{
                cout<<(r+2*c)%5; 
            }
            
        }
        cout<<"\n";
    }
}

int main() {
    
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int t;cin>>t; 

    while(t--){
        solve(); 
    }

}