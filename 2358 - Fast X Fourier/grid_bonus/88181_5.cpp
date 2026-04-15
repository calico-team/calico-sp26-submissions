#include <bits/stdc++.h>
#define pb push_back
#define All(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define f first
#define s second
#define INF (int)(1e18)
#define MOD (int)(1e9+7)
#define MAXN 500005
#define enl '\n'
#define DB(CODE) cout<<'\t'<<CODE<<'\n';
#define SP <<' '<<
#define int long long
typedef long long ll;
using namespace std;
void solve(int *a,int n){ //DB("n" SP n)
    int b[2][n];
    for(int i=0; i<n; i++) b[0][i]=b[1][i]=a[i];
    //for(int i=0; i<n; i++) cout << b[0][i] << ' '; DB(' ')
    //for(int i=0; i<n; i++) cout << b[1][i] << ' '; DB(' ')
    int sc[2]={0};
    for(int i=1; i<n-1; i++) if(b[0][i]>b[0][i-1] && b[0][i]>b[0][i+1]){ //DB("A" SP i SP b[0][i])
        sc[0]+=b[0][i]-max(b[0][i-1],b[0][i+1]);
        b[0][i]=max(b[0][i-1],b[0][i+1]);
    }
    for(int i=1; i<n-1; i++) if(b[0][i]<b[0][i-1] && b[0][i]<b[0][i+1]){ //DB("B" SP i SP b[0][i])
        sc[0]+=min(b[0][i-1],b[0][i+1])-b[0][i];
        b[0][i]=min(b[0][i-1],b[0][i+1]);
    }
    for(int i=1; i<n-1; i++) if(b[1][i]<b[1][i-1] && b[1][i]<b[1][i+1]){ //DB("C" SP i SP b[1][i])
        sc[1]+=min(b[1][i-1],b[1][i+1])-b[1][i];
        b[1][i]=min(b[1][i-1],b[1][i+1]);
    }
    for(int i=1; i<n-1; i++) if(b[1][i]>b[1][i-1] && b[1][i]>b[1][i+1]){ //DB("D" SP i SP b[1][i])
        sc[1]+=b[1][i]-max(b[1][i-1],b[1][i+1]);
        b[1][i]=max(b[1][i-1],b[1][i+1]);
    }
    //for(int i=0; i<n; i++) cout << b[0][i] << ' '; DB(' ')
    //for(int i=0; i<n; i++) cout << b[1][i] << ' '; DB(' ')
    int ver=(sc[1]>sc[0]);
    for(int i=1; i<n-1; i++) a[i]=b[ver][i];
}
void testcase(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    bool open=false;
    vector<pii> itv;
    for(int i=1; i<n-1; i++){
        if(!open && ((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1]))){ //DB(i)
            open=true;
            itv.pb({i-1,n-1});
        } else if(open && !((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1]))){ //DB("C" SP i)
            open=false;
            itv.back().s=i;
        }
    }
    for(int i=0; i<(int)itv.size(); i++) {/*DB(itv[i].f SP itv[i].s)*/ solve(a+itv[i].f,itv[i].s-itv[i].f+1);}
    for(int i=0; i<n; i++) cout << a[i] << ' ';
    cout << enl;
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    cin >> t;
    while(t--){
        testcase();
    }
    return 0;
}

/*

2
5
3 10 1 7 2
5
8 10 1 7 7

*/
