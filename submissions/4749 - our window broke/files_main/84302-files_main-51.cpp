#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b,ans = "";
        cin >> a >> b;
        int bi=0;
        for(int i=0;i<a.length();i++){
            if(a[i]==b[bi]){
                ans += a[i];
                bi++;
            }else{
                ans += '#';
            }
        }
        cout << ans << endl;
    }
}