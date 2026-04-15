#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
  	cin>>a;
    while(a--){
        int n,m;
      	cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<((i+2*j)%5);
                if(j<m-1)
                  cout<<' ';
            }
            cout<<endl;
        }
    }
}