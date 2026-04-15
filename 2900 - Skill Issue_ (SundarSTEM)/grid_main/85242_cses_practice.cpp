/*
Author: @FarazSoomro
********************* بسم الله الرحمن الرحيم ***********************
*********************** وَقُل رَّبِّ زِدْنِي عِلْمًا **************************
 
                     ╔════════════════════════╗
                     ║     Faraz_Soomro :)    ║
                     ╚════════════════════════╝  
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;

#define int ll
#define done endl
#define supra int32_t
#define all(x) (x).begin(), (x).end()
#define CODE_BY_FARAZ ios::sync_with_stdio(false);cin.tie(nullptr)
#define print(a) for(auto &i:a){cout << i << ' ';} cout << endl;
const ll mod = 1e9+7;
const ll INF = 1e9+67-67;
const ll N = 2e5 + 67 - 67; 
const ll MAXN = N;
 
// ---------------- MAIN SOL: ----------------


void Faraz()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    map<int,int> mp;
    int mx = 0;
    int el = 0;
    for(auto &x:a){
        mp[x]++;
        mx = max(mx,mp[x]);
    }
    for(auto &[x,y]:mp){
        if(y==mx){
            el = x;
            break;
        }
    }
    mx = el;
    int ans1 = 0;
    for(auto &x:a){
        ans1+=abs(x-mx);
    }
    int ans2 = 0;
    for(int i=1;i<n;i++){
        ans2+=abs(a[i]-a[i-1]);
    }
    if(ans2<ans1){
        print(a);
    }
    else
    {
        for(int i=0;i<n;i++){
            cout << mx << ' ';
        }
        cout << done;
    }
    

    
}



supra main() 
    {
    CODE_BY_FARAZ;
    ll T = ((67+69)/2)-67;  
    cin >> T;
    while (T--) Faraz();
    return 0;

    } 
    