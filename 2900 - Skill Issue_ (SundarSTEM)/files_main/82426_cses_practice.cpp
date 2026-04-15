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
    string a,b;
    cin >> a >> b;
    int idx = 0;
    vector<pair<int,int>> el;
    int j = 0;
    while(j<a.size() and idx<b.size())
    {
        if(a[j]==b[idx])
        {
            el.push_back(make_pair(j,a[j]));
            idx++;
        }
        j++;

    }
    string ans;
    for(int i=0;i<a.size();i++){
        ans+='#';
    }
    for(auto &[x,y]:el){
        ans[x] = y;
    }
    cout << ans << done;
    
    
}



supra main() 
    {
    CODE_BY_FARAZ;
    ll T = ((67+69)/2)-67;  
    cin >> T;
    while (T--) Faraz();
    return 0;

    } 
    