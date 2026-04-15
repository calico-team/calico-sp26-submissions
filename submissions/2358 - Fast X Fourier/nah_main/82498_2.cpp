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
void testcase(){
    int n,p,r,k;
    cin >> n >> p >> r >> k;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        p-=a[i];
        if(p<0) return (void)(cout << "nah i\'d lose\n");
        if((i+1)%k==0) p+=r;
    }
    cout << "nah i\'d win\n";
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



*/
