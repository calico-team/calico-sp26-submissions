#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        int n=a.length(),m=b.length();
        vector<bool>check(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i]==a[j] && !check[j]){
                    cout << b[i];
                    check[j]=1;
                    break;
                }
                else if(!check[j]){
                    continue;
                }
                else{
                    cout << "#";
                }
            }
        }
        cout << endl;
    }
}