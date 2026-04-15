#include<iostream>
using namespace std;
int main(){
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++){
        int l,w,e,r;
        cin>>l>>w>>e>>r;
        int p=2*(w+l);
        int lap=e/p;
        cout<<lap/r<<endl;
    }
    return 0;
}