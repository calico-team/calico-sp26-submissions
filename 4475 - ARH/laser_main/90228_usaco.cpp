#include <iostream>
using namespace std;

int k;
int n,m;
int p,q;
pair<int,int> asteroids[100010];

pair<int,int> laser_loc(int t){
    int x = (asteroids[0].first+t*q)%n;
    int y = (asteroids[0].second+t*p)%m;
    return{x,y};
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>k>>n>>m>>p>>q;
        for(int i = 0;i<k;i++){
            cin>>asteroids[i].first>>asteroids[i].second;
        }
        int curr_t = 1;
        int ans = -1;
        while(true){
            pair<int,int> curr = laser_loc(curr_t);
            for(int i = 0;i<k;i++){
                if(curr.first==asteroids[i].first&&curr.second==asteroids[i].second){
                    ans = i;
                    break;
                }
            }
            if(ans!=-1) break;
            curr_t++;
        }
        cout<<ans<<endl;
    }
}