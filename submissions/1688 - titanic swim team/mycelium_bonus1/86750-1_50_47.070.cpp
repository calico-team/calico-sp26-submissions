#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        ll xg, yg, xm, ym;
        cin>>xg>>yg>>xm>>ym;
        int D=abs(xg-xm)+abs(yg-ym);
        int B=2*D+5;
        int minx=min(xg, xm)-B;
        int maxx=max(xg, xm)+B;
        int miny=min(yg, ym)-B;
        int maxy=max(yg, ym)+B;
        int W=maxx-minx+1;
        int H=maxy-miny+1;
        auto id=[&](int x, int y) {
            return (x-minx)*H+(y-miny);
        };
        vector<unsigned char> state((size_t)W*H, 0);
        vector<int> grass_front, myc_front;
        grass_front.push_back(id(xg, yg));
        myc_front.push_back(id(xm, ym));
        state[id(xg, yg)]=1;
        state[id(xm, ym)]=2;
        ll ans=1;
        const int dx[4]={1, -1, 0, 0};
        const int dy[4]={0, 0, 1, -1};
        int max_tick=14*D+20;
        for(int tick=1; tick<=max_tick; tick++) {
            vector<int> new_grass, new_myc;
            if(tick%2==0) {
                for(int v:grass_front) {
                    int gx=v/H+minx;
                    int gy=v%H+miny;
                    for(int dir=0; dir<4; dir++) {
                        int nx=gx+dx[dir];
                        int ny=gy+dy[dir];
                        if(nx<minx||nx>maxx||ny<miny||ny>maxy) continue;
                        int nid=id(nx, ny);
                        if(state[nid]==0) {
                            state[nid]=1;
                            new_grass.push_back(nid);
                        }
                    }
                }
            }
            if(tick%7==0) {
                for(int v:myc_front) {
                    int mx2=v/H+minx;
                    int my2=v%H+miny;
                    for(int dir=0; dir<4; dir++) {
                        int nx=mx2+dx[dir];
                        int ny=my2+dy[dir];
                        if(nx<minx||nx>maxx||ny<miny||ny>maxy) continue;
                        int nid=id(nx, ny);
                        if(state[nid]==0) {
                           state[nid]=2;
                           new_myc.push_back(nid);
                           ans++;
                        }
                    }
                }
            }
            if(!new_grass.empty()) grass_front.swap(new_grass);
            else if(tick%2==0) grass_front.clear();
            if(!new_myc.empty()) myc_front.swap(new_myc);
            else if(tick%7==0) myc_front.clear();
            if(myc_front.empty()&&tick%7==0) break;
        }
        cout<<ans<<'\n';
    }
    return 0;
}