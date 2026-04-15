#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(;T--;){
        string a, b; cin >> a >> b;
        int cur = 0;
        string ans = "";
        for(auto it : a){
            if(cur < b.size() && it == b[cur]){
                ans = ans + it;
                cur++;
            } 
            else ans = ans + "#";
        }
        cout << ans << '\n';

    }
}