#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5, M=1e6+5;
int a[N], b[N];
void exgcd(int a, int b, ll &x, ll &y){
    if(!b){
        x=1, y=0;
        return;
    }
    exgcd(b, a%b, y, x);
    x-=(a/b)*y;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    for(int t=1; t<=T; ++t){
        // cerr << "CASE " << t << ":\n";
        int n, m, k, P, Q;
        cin >> k >> n >> m >> Q >> P;
        int sx, sy;
        for(int i=1; i<=k; ++i){
            int x, y;
            cin >> x >> y;
            if(i==1) sx=x, sy=y;
            x=(x+n-sx)%n, y=(y+m-sy)%m;
            a[i]=x, b[i]=y;
        }
        map<int,int> mx, my;
        int tx=0, ty=0;
        for(int X=P; ; X=(X+P)%n){
            mx[X]=++tx;
            if(!X) break;
        }
        for(int Y=Q; ; Y=(Y+Q)%m){
            my[Y]=++ty;
            if(!Y) break;
        }
        // mx[0]=my[0]=0;
        int g=__gcd(tx, ty);
        // cerr << tx << ' ' << ty << '\n';
        tx/=g, ty/=g; ll M=1ll*tx*ty*g;
        int ans=-1, res=1e9;
        for(int i=1; i<=k; ++i){
            ll x=a[i], y=b[i];
            // cerr << "position: "<< x << ' ' << y << '\n';
            
            if(!mx.count(x)||!my.count(y)) continue;
            /*
            t == mx[x] (mod tx*g)
            t == my[y] (mod ty*g)
            */
           ll A=mx[x], B=my[y];
        //    cerr << "step: "<< A << ' ' << B << '\n';
           if(A%g!=B%g) continue;
           exgcd(tx*g,ty*g,x,y);
           x=(A-B)/g*x;
        //    cerr << x << '\n';
           ll ti=A-(tx*g)*x; 
        //    cerr << ti << '\n';
           ti=(ti%M+M)%M; if(i==1) ti=M;
        //    cerr << i-1 << " use " << ti << '\n';
           if(ti<res) ans=i-1, res=ti;
        }
        cout << ans << '\n';
    }
    return 0;
}