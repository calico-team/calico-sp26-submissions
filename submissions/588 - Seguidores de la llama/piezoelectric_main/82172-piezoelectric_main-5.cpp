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
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << c/((2*(a+b))*d) << '\n';
    }
}