#include"bits.h"
using namespace std;
int l,w,e,r,t;
int main(){
    cin>>t;
    while(t--){
        cin>>l>>w>>e>>r;
        cout<<(e/r)/(l*w)<<endl;
    }

    return 0;
}