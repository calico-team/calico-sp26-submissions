// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        int n,p,r,k;
        cin>>n>>p>>r>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        bool win=true;
        int numCurses=0;
        for(int i=0;i<n;i++){
            if(numCurses==k){
                //cout<<"levedl up:"<<i<<endl;
                p+=r;
                numCurses=0;
            }
            p-=v[i];
            numCurses++;
            if(p<0){
                win=false;
                break;
            }
        }
        if(win&&t!=0){
            cout<<"nah i’d win"<<endl;
        }
        else if(t!=0)cout<<"nah i’d lose"<<endl;

        if(t==0){
            if(win){
                cout<<"nah i’d win";
            }
            else {
                cout<<"nah i’d lose";
            }
        }
    }
}
