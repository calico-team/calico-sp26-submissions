#include<bits/stdc++.h>
using namespace std;
int r,l,w,e,k;
int main(){
    cin>>k;
while(k--){
	cin>>l>>w>>e>>r;
	cout<<ceil(ceil(e/r)/(l+w+l+w))<<endl; 
}
    return 0;
}



