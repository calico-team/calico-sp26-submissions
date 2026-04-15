#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back

int n,m;
void sol(){
    int str=0;
    
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << (str+j)%5 << ' ';
        }
        cout << '\n';
        str+=2;
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc=1;
    cin >> tc;
    while(tc--) sol();
}