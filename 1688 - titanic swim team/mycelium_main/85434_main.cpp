#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct State {
    ll t;
    int type;
    int x, y;
    bool operator<(const State& other) const {
        if(t!=other.t) return t>other.t;
        return type>other.type;
    }
};
static inline long long pack(int x, int y) {
    return ((long long)x<<32)^(unsigned int)y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int xg, yg, xm, ym;
        cin>>xg>>yg>>xm>>ym;
        int D=abs(xg-xm)+abs(yg-ym);
        int R=3*D+20;
        int minx=min(xg, xm)-R;
        int maxx=max(xg, xm)+R;
        int miny=min(yg, ym)-R;
        int maxy=max(yg, ym)+R;
        priority_queue<State> pq;
        unordered_map<long long, int> owner;
        owner.reserve((long long)(maxx-minx+1)*(maxy-miny+1)/4+10);
        pq.push({0, 0, xg, yg});
        pq.push({0, 1, xm, ym});
        const int dx[4]={1, -1, 0, 0};
        const int dy[4]={0, 0, 1, -1};
        long long myc=0;
        while(!pq.empty()) {
            auto cur=pq.top();
            pq.pop();
            if(cur.x<minx||cur.x>maxx||cur.y<miny||cur.y>maxy) continue;
            long long key=pack(cur.x, cur.y);
            if(owner.find(key)!=owner.end()) continue;
            owner[key]=cur.type;
            if(cur.type==1) myc++;
            ll w=(cur.type==0?2:7);
            for(int dir=0; dir<4; dir++) {
                int nx=cur.x+dx[dir];
                int ny=cur.y+dy[dir];
                if(nx<minx||nx>maxx||ny<miny||ny>maxy) continue;
                long long nkey=pack(nx, ny);
                if(owner.find(nkey)==owner.end()) {
                    pq.push({cur.t+w, cur.type, nx, ny});
                }
            }
        }
        cout<<myc<<'\n';
    }
    return 0;
}