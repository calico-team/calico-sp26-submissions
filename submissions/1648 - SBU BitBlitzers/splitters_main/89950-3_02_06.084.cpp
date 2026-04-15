#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace__gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define otree tree<ll,ll,less<ll>,rb_tree_tag,tree_order_statistics_node_update> 
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

void solve(){

}

ll gcd(ll a, ll b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}
p64 add(ll num1, ll denom1, ll num2, ll denom2){
    ll common_denom = lcm(denom1,denom2);
    
    ll mult1 = common_denom/denom1;
    ll mult2 = common_denom/denom2;

    ll common_num = num1*mult1+mult2*num2;
    ll cur_gcd = gcd(common_num,common_denom);
    return {common_num/cur_gcd,common_denom/cur_gcd};
}
int main()
{
 fast_cin();
 ll t;
 cin >> t;
 vp32 deltas = {{0,1},{0,-1},{-1,0},{1,0}};
 string opps = "<>v^";
 for(int it=1;it<=t;it++) {
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    forn(i,n) cin>>grid[i];

    if(grid[0][0]=='X'){
        cout<<0<<" "<<1<<ln;
        continue;
    }

    vv32 deg(n+1,v32(m+1));
    vv32 nums(n+1,v32(m+1));
    vv32 denoms(n+1,v32(m+1));
    vector<vector<vp32>> edges(n+1,vector<vp32>(m+1));
    forn(i,n){
        forn(j,m){
            if(grid[i][j]=='^'){
                if(i==0){
                    deg[n][m]+=1;
                    edges[i][j].pb({n,m});
                }
                else {
                    deg[i-1][j]+=1;
                    edges[i][j].pb({i-1,j});
                }
            }
            else if(grid[i][j]=='v'){
                if(i==n-1){
                    deg[n][m]+=1;
                    edges[i][j].pb({n,m});
                }
                else 
                {
                    deg[i+1][j]+=1;
                    edges[i][j].pb({i+1,j});
                }
            }
            else if(grid[i][j]=='<'){
                if(j==0){
                    deg[n][m]+=1;
                    edges[i][j].pb({n,m});
                }
                else {
                    deg[i][j-1]+=1;
                    edges[i][j].pb({i,j-1});
                }
            }
            else if(grid[i][j]=='>'){
                if(j==m-1){
                    deg[n][m]+=1;
                    edges[i][j].pb({n,m});
                }
                else {
                    deg[i][j+1]+=1;
                    edges[i][j].pb({i,j+1});
                }
            }
            else if(grid[i][j]=='S'){
                for(int x=0;x<4;x++){
                    int newi = i+deltas[x].first;
                    int newj = j+deltas[x].second;
                    if(newi<0||newi>=n||newj<0||newj>=m) continue;
                    if(grid[newi][newj]!='.'&&grid[newi][newj]!=opps[x]){
                        edges[i][j].pb({newi,newj});
                        deg[newi][newj]+=1;
                    }
                }
            }
        }
    }

    queue<p32> q;
    nums[0][0]=1;
    denoms[0][0]=1;
    q.push({0,0});
    while(!q.empty()){
        auto [i,j]=q.front();
        //cout<<"on "<<i<<" "<<j<<ln;
        q.pop();
        if(i==n||j==m) continue;
        int num = nums[i][j];
        int denom = denoms[i][j];
        if(grid[i][j]=='S'){
            denom*=edges[i][j].size();
        }

        for(auto &[newi,newj]:edges[i][j]){
            deg[newi][newj]-=1;
            //cout<<"deg "<<newi<<" "<<newj<<" is now "<<deg[newi][newj]<<ln;
            if(deg[newi][newj]==0){
                q.push({newi,newj});
            }
            if(denoms[newi][newj]==0){
                denoms[newi][newj]=denom;
                nums[newi][newj]=num;
            }
            else{
                auto [newnum,newdenom] = add(num,denom,nums[newi][newj],denoms[newi][newj]);
                nums[newi][newj]=newnum;
                denoms[newi][newj]=newdenom;
            }
        }
    }
    if(nums[n][m]==0) cout<<0<<" "<<1<<ln;
    else cout<<nums[n][m]<<" "<<denoms[n][m]<<ln;
    //cout<<ln;
 }
 return 0;
}