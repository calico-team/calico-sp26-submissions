#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <bit>
#define all(x) (x).begin(),(x).end()
#define vec(n) vll arr(n);
#define printarr(arr) for(auto i:arr){cout<<i<<" ";}cout<<endl;
#define printdict(dict) for(auto i:dict)cout<<i.first<<": "<<i.second<<endl;
#define printadj(adj) for(ll i=0;i<n;i++){if(!adj[i].empty()){cout<<i<<": ";printarr(adj[i])}}
#define printadj1(adj1) for(ll i=0;i<n;i++){if(!adj1[i].empty()){cout<<i<<": ";f or(auto j:adj1[i]){cout<<'('+j.first+','+j.second+') '} cout<<endl;}}
#define read(arr); for(ll i=0;i<arr.size();i++) cin>>arr[i];
#define readundirected(m) for(ll i=0;i<m;i++){ll a,b; cin>>a>>b; a--;b--; adj[a].pb(b);adj[b].pb(a);}
#define readdirected(m) for(ll i=0;i<m;i++){ll a,b; cin>>a>>b; a--;b--; adj[a].pb(b);}
#define readundirectedweighted(m) for(ll i=0;i<m;i++){ll a,b,w; cin>>a>>b>>w; a--;b--; adj1[a].pb({b,w});adj1[b].pb({a,w});}
#define readdirectedweighted(m) for(ll i=0;i<m;i++){ll a,b,w; cin>>a>>b>>w; a--;b--; adj1[a].pb({b,w});}
#define readfunc(n) for(ll i=0;i<n;i++){ll a;cin>>a;a--;func_adj[i]=a;}
#define grid(n,m) for (ll i=1;i<=n;i++){for (ll j=1;j<=m;j++) cin>>graph[i][j];}
#define vll vector<ll>
#define sll set<ll>
#define msll multiset<ll>
#define qll queue<ll>
#define pll pair<ll,ll>
#define str string
#define pb push_back
#define ll long long
#define ld long double
using namespace std;
const str alph="abcdefghijklmnopqrstuvwxyz";
const str capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll inf=1e6+1;
const ll graph_size=1e3+2;
const ll mod=1e9+7;
const ld pi=3.141592653589793238462643383279502884197;
const ll large=1e18;
const ll small=-1e18;
vll adj[inf];
vector<pll> adj1[inf];
bool visited[inf];
ll level[inf];
ll parent[inf];
ll distance[graph_size][graph_size];
char graph[graph_size][graph_size];
vector<pll> directions={{0,-1},{-1,0},{1,0},{0,1}};
bool floodfill_visited[graph_size][graph_size];
ll floodfill_level[graph_size][graph_size];
pll floodfill_parent[graph_size][graph_size];
// Fast Input/Output
void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
}
// File Input/Output
str fileio(const str filePath=__FILE__){
    ll lastSlash=filePath.find_last_of('/');
    ll lastDot=filePath.rfind('.');
    return filePath.substr(lastSlash+1,lastDot-lastSlash-1);
}
// For Yes Or No Problems
str yes_or_no(bool test){
    if (test){
       return "YES";
    }
    return "NO";
}
ll k,n,m,p,q;
ll gcd(ll a,ll b){
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
ll egcd(ll a,ll b,ll &x,ll &y){
    if (b==0){
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll g=egcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}
ll crt(ll x,ll n,ll y,ll m){
    x%=n;
    if (x<0){
        x+=n;
    }
    y%=m;
    if (y<0){
        y+=m;
    }
    ll s,t;
    ll g=egcd(n,m,s,t);
    if ((y-x)%g!=0){
        return large;
    }
    ll n2=n/g;
    ll m2=m/g;
    ll rhs=(y-x)/g;
    ll k=(rhs*s)%m2;
    if (k<0){
        k+=m2;
    }
    ll lcm_val=n2*m;
    ll ans=x+n*k;
    ans%=lcm_val;
    if (ans<=0){
        ans+=lcm_val;
    }
    return ans;
}
// Modular Exponentiation
ll exp(ll base,ll pow,ll mod){
    if (base==0 and pow==0){
        return 1;
    }
    if (base==0){
        return 0;
    }
    base%=mod;
    ll ans=1;
    while (pow>0){
        if (pow%2==1){
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        pow/=2;
    }
    return ans;
}
// Modular Inverse
ll mod_inv(ll n,ll mod){
    ll x,y;
    ll g=egcd(n,mod,x,y);
    x%=mod;
    if (x<0){
        x+=mod;
    }
    return x;
}
// Precomputing Factorials
ll factorials[inf];
void fact(ll mod){
    factorials[0]=1;
    for (ll i=1;i<=inf;i++){
        factorials[i]=factorials[i-1]*i;
        factorials[i]%=mod;
    }
}
// Calculating Combinations
ll choose(ll n,ll k,ll mod){
    ll ans=factorials[n];
    ans*=mod_inv(factorials[k],mod);
    ans%=mod;
    ans*=mod_inv(factorials[n-k],mod);
    ans%=mod;
    return ans;
}
int main(){
    // auto start_time=chrono::steady_clock::now();
    fastio();
    // str filename=fileio();
    // ifstream cin(filename+".in");
    // ofstream cout(filename+".out");
    cout<<setprecision(20);
    ll t=1;
    cin>>t;
    while (t--){
        cin>>k>>n>>m>>p>>q;
        vector<pll> arr(k);
        for (ll i=0;i<k;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        ll val=gcd(q,n);
        ll val1=gcd(p,m);
        vll ans(k,large);
        for (ll i=0;i<k;i++){
            if ((arr[i].first-arr[0].first)%val==0 and (arr[i].second-arr[0].second)%val1==0){
                ll x=(arr[i].first-arr[0].first)/val*mod_inv(q/val,n/val);
                ll y=(arr[i].second-arr[0].second)/val1*mod_inv(p/val1,m/val1);
                ans[i]=crt(x,n/val,y,m/val1);
            }
        }
        ll curr=large;
        ll ans_val=0;
        for (ll i=0;i<k;i++){
            if (ans[i]<curr){
                curr=ans[i];
                ans_val=i;
            }
        }
        cout<<ans_val<<"\n";
    }
    // auto end_time=chrono::steady_clock::now();
    // auto elapsed_time=chrono::duration_cast<chrono::milliseconds>(end_time-start_time);
    // cout<<"Elapsed time: "<<elapsed_time.count()<<" milliseconds\n";
}
