#include<bits/stdc++.h>
using namespace std;

int t,l,w,e,r;

int main() {
    cin>>t;
    for (int i=1;i<=t;i++) {
        cin>>l>>w>>e>>r;
        cout<<e/r/(2*(l+w))<<"\n";
    }
}