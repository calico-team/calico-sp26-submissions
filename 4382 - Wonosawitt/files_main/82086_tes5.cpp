#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back

string a,b;
void sol(){
    cin >> a >> b;

    int ite=0;

    for(int i=0;i<a.size();i++){
        if(a[i]==b[ite]){
            ite++;
        }else a[i]='#';
    }

    cout << a << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc=1;
    cin >> tc;
    while(tc--) sol();
}