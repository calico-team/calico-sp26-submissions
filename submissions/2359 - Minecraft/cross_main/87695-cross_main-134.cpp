#include<bits/stdc++.h>
using namespace std;

int g[5][5];
bool f=0;

bool c(int r,int t){
    set<int>d;
    d.insert(g[r][t]);
    d.insert(g[r-1][t]);
    d.insert(g[r+1][t]);
    d.insert(g[r][t-1]);
    d.insert(g[r][t+1]);
    return d.size()==5;
}

void d(int r,int t){
    if(f)return;
    if(r==5){
        cout<<"Found a 5x5 Base Pattern:\n";
        for(int i=0;i<5;++i){
            for(int j=0;j<5;++j){
                cout<<g[i][j]<<" ";
            }
            cout<<"\n";
        }
        f=1;
        return;
    }
    int nr=(t==4)?r+1:r;
    int nt=(t==4)?0:t+1;
    for(int n=0;n<=4;++n){
        g[r][t]=n;
        bool v=1;
        if(r>=2&&t>=1&&t<=3){
            if(!c(r-1,t))v=0;
        }
        if(v)d(nr,nt);
    }
}

int main(){
    d(0,0);
    return 0;
}