#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;

void solve(){
    cin >> n >> m;
    int now=0,st=0;
    for(int i=1;i<=n;i++){
        st=now;
        for(int j=1;j<=m;j++){
            cout << now << " ";
            now = (now+1)%5;
        }
        now=(st+2)%5;
        cout << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int q=1;
    cin >> q;
    while(q--)solve();
    return 0;
}