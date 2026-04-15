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
    vl ans(n,0);
    ans[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        ans[i] = min(a[i],ans[i+1]);
    }
    print(ans)
    
    
}



supra main() 
    {
    CODE_BY_FARAZ;
    ll T = ((67+69)/2)-67;  
    cin >> T;
    while (T--) Faraz();
    return 0;

    } 
    