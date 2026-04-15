#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll l, w, e, r, i, t, p;
    cin>>t;
    for(i=1; i<=t; i++){
        cin>>l>>w>>e>>r;
        p=l+w+l+w;
        p*=r;
        cout<<e/p<<endl;
    }
    return 0;
}
