#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int l,w,e,r;
        cin >> l >> w >> e >> r;
        int cnt=ceil(1.0*e/r);
        int len=2*l+2*w;
        cout << ceil(1.0*cnt/len) << endl;
    }
}