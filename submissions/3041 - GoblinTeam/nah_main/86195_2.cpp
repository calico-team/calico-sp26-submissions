#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);cin.tie(0);
int t;cin>>t;
while(t--){
int n,p,r,k;cin>>n>>p>>r>>k;
int c=0;
bool w=1;
for(int i=0;i<n;i++){
int x;cin>>x;
if(w){
if(p<x)w=0;
else{
p-=x;
c++;
if(c==k&&i!=n-1){p+=r;c=0;}
}
}
}
cout<<(w?"nah i'd win":"nah i'd lose")<<endl;
}
return 0;
}