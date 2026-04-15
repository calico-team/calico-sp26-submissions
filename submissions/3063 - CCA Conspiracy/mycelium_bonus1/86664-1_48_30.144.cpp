#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    set<pair<int,int>>gree,purp;
    set<pair<int,int>>bg,bp;
    gree.insert({a,b});
    purp.insert({c,d});
    bg.insert({a,b});
    bp.insert({c,d});
    bool good=0;
    int time=0;
    int pvp=sz(purp);
    while(!good){
        time++;
        if(time%2!=0 && time%7!=0) continue;
        set<pair<int,int>>ng,np;
        if(time%2==0){
            set<pair<int,int>>gera;
            for(auto [x,y]: bg){
                bool useful=0;
                for(auto [dx,dy]: dirs){
                    if(gree.count({x+dx,y+dy}) || purp.count({x+dx,y+dy})) continue;
                    useful=1;
                    ng.insert({x+dx,y+dy});
                }
                if(!useful){
                    gera.insert({x,y});
                }
            }
            for(auto u: ng){
                gree.insert(u);
                bg.insert(u);
            }
            for(auto u: gera){
                bg.erase(u);
            }
        }
        if(time%7==0){
            set<pair<int,int>>pera;
            for(auto [x,y]: bp){
                bool useful=0;
                for(auto [dx,dy]: dirs){
                    if(gree.count({x+dx,y+dy}) || purp.count({x+dx,y+dy})) continue;
                    useful=1;
                    np.insert({x+dx,y+dy});
                }
                if(!useful){
                    pera.insert({x,y});
                }
            }
            for(auto u: np){
                purp.insert(u);
                bp.insert(u);
            }
            for(auto u: pera){
                bp.erase(u);
            }
            if(sz(np)==0){
                good=1;
            }
        }
    }
    cout<<sz(purp)<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}
