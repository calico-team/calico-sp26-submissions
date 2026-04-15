#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define f first
#define s second 
#pragma GCC optimize("unroll-loops,O3")
#pragma GCC target("avx,avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

void open(string name = ""){
    cin.tie(0)->sync_with_stdio(0); 
    if(name=="omitir") return;
    freopen((name + ".in").c_str(), "r", stdin);
    if(name != "soloinput")freopen((name + ".out").c_str(), "w", stdout);
}

int main(){
    open("omitir");
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto&i:v) cin >> i;
        sort(v.begin(),v.end());
        ll x1 = v[(n+1)/2-1], x2 = v[(n+1)/2];
        ll tot1=0,tot2=0;
        for(int i = 0; i < n; i++){
            tot1+=llabs(x1-v[i]);
            tot2+=llabs(x2-v[i]);
        }
        if(tot1<tot2){
            for(int i = 0; i < n; i++) cout << x1 << ' ';
        }else{
            for(int i = 0; i < n; i++) cout << x2 << ' ';
        }
        cout << '\n';
    }
}