#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1; cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> v(n);
        int prev = 0;
        if(n==1){
            int a; cin>>a;
            cout<<a<<nl;
        }else if(n==2){
            int a,b; cin>>a>>b;
            cout<<a<<" "<<b<<nl;
        }else{
            for(int i = 0; i < n; i++){
                cin>>v[i];
            }
            for(int i = 0; i < n; i++){
                if(i==0||i==n-1){
                    cout<<v[i]<<" ";
                    prev = v[i];
                }else{
                    int check = i+1;
                    while(check<n&&abs(v[check]-v[i])==abs(v[check]-prev)) check++;
                    if(check==n || abs(v[check]-v[i])<abs(v[check]-prev)){
                        cout<<v[i]<<" ";
                        prev = v[i];
                    }else{
                        cout<<prev<<" ";
                    }
                    
                }
            }
            cout<<nl;
        }


    }

    return 0;
}