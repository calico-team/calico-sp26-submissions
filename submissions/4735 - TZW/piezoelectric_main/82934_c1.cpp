#include<bits/stdc++.h>
using namespace std;
int l,w,e,r,t;
int main(){
    cin>>t;
    while(t--){
        cin>>l>>w>>e>>r;
        int x = (e/r)/((l+w)*2);
        if((e/r)%((l+w)*2) != 0)
            x = x+1;
        cout<<x<<endl;
    }

    return 0;
}