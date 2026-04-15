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
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout << (2*i+j)%5 << ' ';
        cout << enl;
    }
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
