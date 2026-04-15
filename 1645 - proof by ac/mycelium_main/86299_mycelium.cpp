// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(){
    ll xg, yg, xm, ym;
    cin>>xg>>yg>>xm>>ym;
    ll n = 100;
    xg+=n/2;
    yg+=n/2;
    xm+=n/2;
    ym+=n/2;

    vector<vector<ll>> grid(n,vector<ll>(n));
    vector<vector<ll>> next_grid;
    grid[yg][xg] = 1;
    grid[ym][xm] = 2;

    for(ll t = 1;t<500;++t){

        
        next_grid = grid;
        if(t%7 == 0){
            for(int i = 0;i<n;++i){
                for(ll j = 0;j<n;++j){
                    if(grid[i][j] == 2){
                        if(i!=0 && grid[i-1][j] == 0){
                            next_grid[i-1][j] = 2;
                        }
                        if(i!=n-1 && grid[i+1][j] == 0){
                            next_grid[i+1][j] = 2;
                        }
                        if(j!=0 && grid[i][j-1] == 0){
                            next_grid[i][j-1] = 2;
                        }
                        if(j!=n-1 && grid[i][j+1] == 0){
                            next_grid[i][j+1] = 2;
                        }

                    }
                }
            }
        }
        


        if(t%2 == 0){
            for(ll i = 0;i<n;++i){
                for(ll j = 0;j<n;++j){
                    if(grid[i][j] == 1){
                        if(i!=0 && grid[i-1][j] == 0){
                            next_grid[i-1][j] = 1;
                        }
                        if(i!=n-1 && grid[i+1][j] == 0){
                            next_grid[i+1][j] = 1;
                        }
                        if(j!=0 && grid[i][j-1] == 0){
                            next_grid[i][j-1] = 1;
                        }
                        if(j!=n-1 && grid[i][j+1] == 0){
                            next_grid[i][j+1] = 1;
                        }

                    }
                }
                
            }
        }
        grid = next_grid;
        /*
        if(t%2 == 0 || t%7 == 0){
            for(ll i = 20;i<30;++i){
                for(ll j = 20;j<30;++j){
                    cout<<grid[i][j]<<" ";
                }cout<<endl;
                
            }
            
        }cout<<endl;*/

    }

    ll cnt = 0;
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<n;++j){
            if(grid[i][j] == 2){
                ++cnt;
            }
        }
        
    }
    cout<<cnt<<endl;

}

int main() {
    ll T;
    cin>>T;
    while(T--){
        solve();
    }
}
