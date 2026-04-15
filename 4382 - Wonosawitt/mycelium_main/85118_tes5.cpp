#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back

int x,y;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void sol(){
    int gr[205][205]{};

    int area=1;
    queue<pair<int,int>> g, m;

    cin >> x >> y;
    g.push({x+100,y+100});
    gr[x+100][y+100]=1;

    cin >> x >> y;
    m.push({x+100,y+100});
    gr[x+100][y+100]=2;

    auto spreadg = [&](){
        queue<pair<int,int>> tmp;

        while(!g.empty()){
            auto[a,b]=g.front(); g.pop();

            for(int i=0;i<4;i++){
                if(gr[a+dx[i]][b+dy[i]]==0) {
                    tmp.push({a+dx[i], b+dy[i]});
                    gr[a+dx[i]][b+dy[i]]=1;
                }
            }
        }
        g=tmp;
    };

    auto spreadm = [&](){
        queue<pair<int,int>> tmp;

        while(!m.empty()){
            auto[a,b]=m.front(); m.pop();
            
            for(int i=0;i<4;i++){
                if(gr[a+dx[i]][b+dy[i]]==0){
                    area++;
                    tmp.push({a+dx[i], b+dy[i]});
                    gr[a+dx[i]][b+dy[i]]=2;
                }
            }
        }
        m=tmp;
    };

    int tick=1;
    while(!m.empty()){
        tick++;

        if(tick%2==0) spreadg();
        if(tick%7==0) spreadm();
    }

    cout << area << '\n';
    // for(int i=90;i<120;i++){
    //     for(int j=90;j<120;j++){
    //         cout << gr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc=1;
    cin >> tc;
    while(tc--) sol();
}