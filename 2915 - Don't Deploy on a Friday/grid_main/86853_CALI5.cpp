#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<long long> vll; 
typedef long long ll;
const int INF = 0x3f3f3f3f; const ll LLINF = 0x3f3f3f3f3f3f3f3f;
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (b); --i)
#define scan(x) cin >> x
#define scann(x) int x; cin >> x
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define local freopen("zDAT.txt", "r", stdin);
#define scanArr(arr, n)  FR(i, n) scan(arr[i])
#define scanArr2D(arr, n, m) FR(i, n) FR(j, m) scan(arr[i][j])
#define SZ(v) ((int) (v).size())
#define ALL(v) begin(v),end(v)
#define pb push_back
#define fs first
#define sd second
const bool DEBUG_MODE = true;
#define dbg(x) if (DEBUG_MODE) {cerr << #x << ' ' << (x) << endl;}
#define dbgArr(arr,n) if(DEBUG_MODE){ cerr<<#arr<<": "; FR(_i,n) cerr<<(arr)[_i]<<" "; cerr<<endl; }
#define dbgArrP(arr,n) if(DEBUG_MODE){ cerr<<#arr<<": "; FR(_i,n) cerr<<"("<<(arr)[_i].fs<<","<<(arr)[_i].sd<<") "; cerr<<endl; }
#define dbgArr2D(arr,m,n) if(DEBUG_MODE){ cerr<<#arr<<":\n"; FR(i,m){ FR(j,n) cerr<<arr[i][j]<<" "; cerr<<endl; } }
void solve() {
    int n;
    cin >> n;
    vi arr(n);
    scanArr(arr,n);
    cout << arr[0] << " " << max(arr[0],arr[2])<< " " << arr[2] << "\n";
    
    
    
    
}
 
int32_t main() {
    #ifdef DMOJ
        local
    #endif
    fast
    scann(t);
    while(t--){
        solve();
    }
   
 
    return 0;
}