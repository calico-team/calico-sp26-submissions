#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int MOD = 998244353, N = 2e5+5;

void slave(){

    int k,n,m,p,q;
    cin>>k>>n>>m>>p>>q;
    vector<vector<int>> grid(m,vector<int>(n,0));
    

    int curx=0,cury=0;

    for(int i=0;i<k;++i){

        int x,y;
        cin>>x>>y;

        if(!i){

            curx=x;
            cury=y;

        }

        grid[y][x]=i+1;

    }

    cury=(cury+p)%m;
    curx=(curx+q)%n;

    while(!grid[cury][curx]){

        cury=(cury+p)%m;
        curx=(curx+q)%n;

    }

    cout<<grid[cury][curx]-1<<endl;
        
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