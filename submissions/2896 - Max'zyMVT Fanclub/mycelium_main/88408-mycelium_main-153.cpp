#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N(1999);

int x1,y11,x2,y2;
vector<pair<int,int>> vp = {{1,0},{-1,0},{0,1},{0,-1}};
int tab[N][N];

void solve(){
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)tab[i][j]=0;
    cin >> x1 >> y11 >> x2 >> y2;
    int area=1;
    queue<pair<int,int>> q1,q2;
    q1.push({x1+100,y11+100});
    tab[x1+100][y11+100]=1;
    q2.push({x2+100,y2+100});
    tab[x2+100][y2+100]=2;
    int t=1;
    while(!q1.empty() || !q2.empty()){
        auto sz = q1.size();
        while(t%2==0 && sz--){
            auto [x,y]=q1.front(); q1.pop();
            for(auto [nx,ny]:vp){
                nx+=x,ny+=y;
                if(nx<0||ny<0||nx>=N||ny>=N)continue;
                if(tab[nx][ny]==0){
                    tab[nx][ny]=1;
                    q1.push({nx,ny});
                }
            }
        }
        sz = q2.size();
        while(t%7==0 && sz--){
            auto [x,y]=q2.front(); q2.pop();
            for(auto [nx,ny]:vp){
                nx+=x,ny+=y;
                if(nx<0||ny<0||nx>=N||ny>=N)continue;
                if(tab[nx][ny]==0){
                    tab[nx][ny]=2;
                    q2.push({nx,ny});
                    area++;
                }
            }
        }
        t++;
    }
    // for(int i=0;i<=20;i++){
    //     for(int j=0;j<=20;j++){
    //         cout << tab[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << area << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int q=1;
    cin >> q;
    while(q--)solve();
    return 0;
}