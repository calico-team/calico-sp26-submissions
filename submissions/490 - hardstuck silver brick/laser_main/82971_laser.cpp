#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int k,n,m,p,q;
        cin>>k>>n>>m>>p>>q;
        int startX,startY;
        int arr[n][m];
        memset(arr,-1,sizeof arr);
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            if(i==0){startX=x;startY=y;}
            arr[x][y]=i;
        }
        int x=(startX+q)%n,y=(startY+p)%m;
        bool c=false;
        while(x!=startX||y!=startY){
            if(arr[x][y]!=-1){
                cout<<arr[x][y]<<endl;
                c=true;
                break;
            }
            x=(x+q)%n;
            y=(y+p)%m;
        }
        if(!c)cout<<0<<endl;
    }
}
