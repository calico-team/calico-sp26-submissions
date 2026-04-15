#include<bits/stdc++.h>
using namespace std;

void s(){
    int n,m;
    cin>>n>>m;
    int g[5][5]={
        {0,1,2,3,4},
        {2,3,4,0,1},
        {4,0,1,2,3},
        {1,2,3,4,0},
        {3,4,0,1,2}
    };
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<g[i%5][j%5];
            if(j<m-1)cout<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int t;
    if(cin>>t)while(t--)s();
    return 0;
}
