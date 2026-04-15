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
ll n,m,q;
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
        str a,b;
        cin>>a>>b;
        sll inds;
        ll curr_a=0;
        ll curr_b=0;
        while (curr_b<b.length()){
            while (a[curr_a]!=b[curr_b]){
                curr_a++;
            }
            inds.insert(curr_a);
            curr_a++;
            curr_b++;
        }
        for (ll i=0;i<a.length();i++){
            if (inds.count(i)){
                cout<<a[i];
            }
            else{
                cout<<'#';
            }
        }
        cout<<"\n";
    }
    // auto end_time=chrono::steady_clock::now();
    // auto elapsed_time=chrono::duration_cast<chrono::milliseconds>(end_time-start_time);
    // cout<<"Elapsed time: "<<elapsed_time.count()<<" milliseconds\n";
}
