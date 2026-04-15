#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
constexpr int maxn = 5000;
bool cov[maxn][maxn]{};

void solve(){
    memset(cov,0,sizeof(cov));
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    set<pair<int,int>>bg,bp;
    auto iscov = [&](int xv, int yv) -> bool {
        return cov[xv+2500][yv+2500];
    };
    auto covv = [&](int xv, int yv) -> void {
        cov[xv+2500][yv+2500]=1;
    };
    int purp=1;
    covv(a,b);
    covv(c,d);
    bg.insert({a,b});
    bp.insert({c,d});
    bool good=0;
    int time=0;
    while(!good){
        time++;
        if(time%2!=0 && time%7!=0) continue;
        set<pair<int,int>>ng,np;
        if(time%2==0){
            vector<pair<int,int>>gera;
            for(auto [x,y]: bg){
                bool useful=0;
                for(auto [dx,dy]: dirs){
                    if(iscov(x+dx,y+dy)) continue;
                    useful=1;
                    ng.insert({x+dx,y+dy});
                }
                if(!useful){
                    gera.push_back({x,y});
                }
            }
            for(auto u: ng){
                covv(u.first,u.second);
                bg.insert(u);
            }
            for(auto u: gera){
                bg.erase(u);
            }
        }
        if(time%7==0){
            vector<pair<int,int>>pera;
            for(auto [x,y]: bp){
                bool useful=0;
                for(auto [dx,dy]: dirs){
                    if(iscov(x+dx,y+dy)) continue;
                    useful=1;
                    np.insert({x+dx,y+dy});
                }
                if(!useful){
                    pera.push_back({x,y});
                }
            }
            for(auto u: np){
                covv(u.first,u.second);
                bp.insert(u);
                purp++;
            }
            for(auto u: pera){
                bp.erase(u);
            }
            if(sz(np)==0){
                good=1;
            }
        }
    }
    cout<<purp<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}
