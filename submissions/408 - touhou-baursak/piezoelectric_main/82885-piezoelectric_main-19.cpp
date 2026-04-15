#include <bits/stdc++.h>
using namespace std;

void setup(){

}
void solve(){
    int l,w,e,r;
    cin>>l>>w>>e>>r;
    int p = 2*(l+w);
    cout<<((e+r*p-1)/(r*p))<<"\n";



}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }

}
//HATSUNE MIKU WILL MAKE ME WIN CALICO