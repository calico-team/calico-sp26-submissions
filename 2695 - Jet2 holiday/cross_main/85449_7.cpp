#include <iostream>
using namespace std;
int T;
int n;
int m;
int main() {
   cin>>T;
   for(int i=1;i<=T;i++){
    cin>>m>>n;
    int a[m][n]={0};
    for(int j=0;j<m;j++){
        for(int k=0;k<n;k++){
            a[j][k]=(j+2*k)%5;
            cout<<a[j][k]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;   
       
       
   }
   
    
    return 0;
}