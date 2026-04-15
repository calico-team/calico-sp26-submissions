#include <iostream>
using namespace std;

int main(){
    int l,w;
    int r, e;
    int t;
    cin>>t;
    while(t--){
        cin>>l>>w>>e>>r;
        int p=2*(l+w);
        cout<<e/(r*p)<<endl;
    }
}