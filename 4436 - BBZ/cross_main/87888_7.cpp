#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout << (j+2*i)%5 << " ";
            }
            cout << endl;
        }
    }
}