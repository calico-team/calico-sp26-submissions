#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int MOD = 998244353, N = 2e5+5;

void slave(){

    int k,n,m,p,q;
    cin>>k>>n>>m>>p>>q;

    int curx=0,cury=0;

    map<pair<int,int>,int> gyatt;


    for(int i=0;i<k;++i){

        int x,y;
        cin>>x>>y;

        if(!i){

            curx=x;
            cury=y;

        }

        gyatt[{x,y}]=i+1;

    }

    cury=(cury+p)%m;
    curx=(curx+q)%n;

    while(gyatt.find({curx,cury})==gyatt.end()){

        cury=(cury+p)%m;
        curx=(curx+q)%n;

    }

    cout<<gyatt[{curx,cury}]-1<<endl;
        
}

signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--){
        
        slave();
        
    }
    
}