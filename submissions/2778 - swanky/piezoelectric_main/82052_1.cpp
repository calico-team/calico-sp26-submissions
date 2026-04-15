#include<iostream>
using namespace std;

int main(){
    int test;
    cin>>test;
    for(int t=0;t<test;t++){
        int l,w,e,r;
        cin>>l>>w>>e>>r;
        int p=l+l+w+w;
        int gen=p*r;
        cout<<e/gen<<endl;
    }
}