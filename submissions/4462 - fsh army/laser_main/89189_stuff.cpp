#include <iostream> 
#include <cmath> 
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <unordered_set>
#include <stack>
#include <random>
#include <chrono>
#include <bitset>
#include <complex>
#include <cassert>
#include <functional>
#include <ctime>



#pragma GCC optimize ("O3")

using namespace std; 



#define ll long long
#define f first
#define s second


// 0 or n - 1 => [a[i], b[i + 1]]
// a, b, c => a[i]
// a, c, b => b[i + 1]
// b, a, c => b[i - 1]

// 1 3 4 2
// 
void solve() {
    ll k,n,m,p,q; cin>>k>>n>>m>>p>>q;
    map<ll,vector<int>> ast;
    vector<pair<ll,ll>> x(k);
    ll cur;
    for(int i = 0; i < k; i++) {
        ll a,b; cin>>a>>b;
        ll key=((a*p-b*q)%(n*p)+(n*p))%(n*p);
        if (i==0)cur=key;
        ast[key].push_back(i);
        x[i]={a,b};
    }
    for (int j=0; 1; j++){
        if (ast[cur].size()==0||(j==0&&ast[cur].size()==1&&ast[cur][0]==0)){
            inc:
            cur=(((m*q))+cur)%(n*p);
            if (cur<0)cur+=(n * p);
            continue;
        }
        int ind=-1;
        for (int i=0; i<ast[cur].size(); i++){
            if (j==0&&x[ast[cur][i]].f<=x[0].f)continue;
            if (ind==-1||x[ind].f>x[ast[cur][i]].f)ind=ast[cur][i];
        }
        if (ind==-1) goto inc;
        cout<<ind<<'\n'; break;
    }
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int t; cin >> t; 
    
    while(t--) solve(); 
}