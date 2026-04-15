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
        int idx=-1;
        for(int i=0;i<m;i++){
            for(int j=idx+1;j<n;j++){
                if(b[i]==a[j]){
                    cout << b[i];
                    idx=j;
                    break;
                }
                else{
                    cout << "#";
                }
            }
        }
        if(idx+1<n){
            for(int i=idx+1;i<n;i++) cout << "#";
        }
        cout << endl;
    }
}