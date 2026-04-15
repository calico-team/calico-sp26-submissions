#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    vector<int> xd={1,-1,0,0}, yd={0,0,1,-1};
    int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;

    set<pair<int,int>> grid;
    grid.insert({x1,y1});
    grid.insert({x2,y2});

    vector<pair<int,int>> ab={{x1,y1}};
    vector<pair<int,int>> bb={{x2,y2}};

    ll ans=1;
    int t=1;

    while (!bb.empty()){
        set<pair<int,int>> na,nb;
        if(t%2==0){
            for(auto c:ab){
                for(int i=0;i<4;i++){
                    pair<int,int> next={c.first+xd[i],c.second+yd[i]};
                    if(grid.count(next)==0) na.insert(next);
                }
            }
        }
        if(t%7==0){
            for(auto c:bb){
                for(int i=0;i<4;i++){
                    pair<int,int> next={c.first+xd[i],c.second+yd[i]};
                    if(grid.count(next)==0) nb.insert(next);
                }
            }
        }
        if(t%2==0){
            ab.clear();
            for(auto c:na){
                if(grid.count(c)==0) ab.push_back(c);
                grid.insert(c);
            }
        }
        if(t%7==0){
            bb.clear();
            for(auto c:nb){
                if(grid.count(c)==0){
                    bb.push_back(c);
                    ans++;
                }
                grid.insert(c);
            }
        }
        t++;
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while (t--) solve();
}
