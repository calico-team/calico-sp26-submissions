#include <bits/stdc++.h>
using namespace std;
int n;
int l,w,e,r;
int a;
int ans;
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
       cin>>l>>w>>e>>r;
       a=(l+w)*2*r;
       ans=e/a;
       cout<<ans<<endl;
       
   }
}