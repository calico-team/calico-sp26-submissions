#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005, V=2*N;
string a[N];
int cz[N][N];
int b[V][V], s[V][V];
int c[V][V], sc[V][V];
int n, m, k;
int gt(int x, int y, int L){
    return s[x+L][y+L]-s[x-1][y+L]-s[x+L][y-1]+s[x-1][y-1];
}
ll gc(int x, int y, int L){
    return sc[x+L][y+L]-sc[x-1][y+L]-sc[x+L][y-1]+sc[x-1][y-1];
}
int px, py;
bool check(int mid){
    px=py=-1; int res=1e9;
    for(int i=1; i+mid<=n+m; ++i){
        for(int j=1; j+mid<=n+m; ++j){
            if(gt(i,j,mid)>=k){
                if(px==-1){
                    px=i, py=j; res=gc(i,j,mid);
                }else if(gc(i,j,mid)<res){
                    px=i, py=j;
                }
            }
        }
    }
    if(px!=-1) return 1;
    return 0;
}
void output(int L){
    int ct=0;
    for(int i=px; i<=px+L; ++i){
        for(int j=py; j<=py+L; ++j){
            if(ct<k&&b[i][j]){
                int x=(i+j-m)/2, y=(i-j+m)/2;
                assert((i+j-m)%2==0);
                assert((i-j+m)%2==0);
                cout << x-1 << ' ' << y-1 << '\n';
                ct++;
            }
        }
    }
    cout.flush();
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        for(int i=1; i<=n; ++i){
            cin >> a[i];
            a[i]='#'+a[i];
        }
        for(int i=1; i<=n+m; ++i){
            for(int j=1; j<=n+m; ++j){
                b[i][j]=c[i][j]=0;
            }
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                cz[i][j]=0;
            }
        }
        for(int i=1; i<=n; ++i){
            int ct=0;
            for(int j=1; j<=m; ++j){
                if(a[i][j]=='-'){
                    b[i+j][i+m-j]++;
                    cz[i][j]=ct;
                }else{
                    ct++;
                }
            }
            ct=0;
            for(int j=m; j>=1; --j){
                if(a[i][j]=='-'){
                    cz[i][j]=min(cz[i][j], ct);
                }else{
                    ct++;
                }
            }
            for(int j=1; j<=m; ++j){
                if(a[i][j]=='-'){
                    c[i+j][i+m-j]=cz[i][j];
                }
            }
        }
        
        for(int i=1; i<=n+m; ++i){
            for(int j=1; j<=n+m; ++j){
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+b[i][j];
                sc[i][j]=sc[i-1][j]+sc[i][j-1]-sc[i-1][j-1]+c[i][j];
            }
        }
        int l=0, r=n+m, mid;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid)) r=mid-1;
            else l=mid+1;
        }
        // cout << l << '\n';
        assert(check(l));
        output(l);
    }
    return 0;
}