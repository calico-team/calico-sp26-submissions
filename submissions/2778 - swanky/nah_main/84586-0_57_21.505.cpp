#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int test=0;test<t;test++){
        int n,p,r,k;
        cin>>n>>p>>r>>k;
        int last=0;
        bool ok=true;
        for(int i=0;i<n;i++){
            int e;
            cin>>e;
            if(p-e>=0){
                p-=e;
                continue;
            }
            if(i-last>=k){
                last=i;
                p+=r;
            }
            p-=e;
            if(p<0)
                ok=false;
        }
        if(ok)
            cout<<"nah i'd win"<<endl;
        else 
            cout<<"nah i’d lose"<<endl;
    }
}










