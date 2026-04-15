#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int l,w,e,r;
        cin>>l>>w>>e>>r;
        int p=2*l+2*w;
        double lapE=p*r;
        cout<<ceil(e/lapE)<<endl;
    }
}
