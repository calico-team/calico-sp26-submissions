#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        long long xg,yg,xm,ym;
        cin>>xg>>yg>>xm>>ym;
        long long d=abs(xg-xm)+abs(yg-ym);
        long long ans=d*d;
        cout<<ans<<"\n";
    }
}