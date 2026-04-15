#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define pp pop_back
#define ll long long
#define pb push_back
#define ls(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define wr cout << "------------------------" << endl

void solution();

signed main(){
#ifdef parad0x
    freopen("file.in","r",stdin);
#endif
    #define print(...) 42

    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solution();
    }
    return 0;
}

void solution(){
    int l, w, e, r;
    cin >> l >> w >> e >> r;
    cout << e / (2 * r * (l + w)) << endl;
}