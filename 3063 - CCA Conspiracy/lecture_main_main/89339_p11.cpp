#include "bits/extc++.h"

using namespace std;

constexpr int maxn = 4005;
string grid[maxn];
bool rot[maxn][maxn];
int pref[maxn][maxn];

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 0; i<n; i++){
        cin>>grid[i];
    }
    memset(rot,0,sizeof(rot));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            rot[i+j][i-j+(m-1)]=(grid[i][j]=='-');
        }
    }
    for(int i = 0; i<=n+m; i++){
        pref[i][0]=0;
        pref[0][i]=0;
    }
    for(int i = 0; i<=n+m; i++){
        for(int j = 0; j<=n+m; j++){
            pref[i+1][j+1]=pref[i+1][j]+pref[i][j+1]-pref[i][j]+rot[i][j];
        }
    }
    auto sumv = [&](int xl, int xr, int yl, int yr) -> int {
        return pref[xr+1][yr+1]-pref[xr+1][yl]-pref[xl][yr+1]+pref[xl][yl];
    };
    int lv=0,rv=n+m;
    auto check = [&](int x) -> bool {
        if(x>=(n+m-2)) return 1;
        for(int i = 0; i<n+m-x; i++){
            for(int j = 0; j<n+m-x; j++){
                if(sumv(i,i+x-1,j,j+x-1)>=k){
                    return 1;
                }
            }
        }
        return 0;
    };
    while(lv+1<rv){
        int mid = (lv+rv)/2;
        if(check(mid)){
            rv=mid;
        }else{
            lv=mid;
        }
    }
    for(int i = 0; i<n+m-rv; i++){
        for(int j = 0; j<n+m-rv; j++){
            if(sumv(i,i+rv-1,j,j+rv-1)>=k){
                int cnt=0;
                for(int ansx = i; ansx<i+rv; ansx++){
                    for(int ansy = j; ansy<j+rv; ansy++){
                        if(cnt==k) break;
                        if(rot[ansx][ansy]){
                            int finx=((ansx+ansy)-(m-1))/2;
                            cout<<finx<<" "<<ansx-finx<<"\n";
                            cnt++;
                        }
                    }
                }
                return;
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}
