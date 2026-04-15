#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t; cin >> t;
    while (t--){
        ll a; cin >> a;
        vector <ll> v(a);
        for (int i = 0; i < a; i++) cin >> v[i];
        if (a == 1) cout << v[0] << endl;
        else if (a == 2) cout << v[0] << " " << v[0] << endl;
        else{
            sort(v.begin(), v.end());
            cout << v[1] << " " << v[1] << " " << v[1] << endl;
        }
    }
}