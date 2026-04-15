#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
using namespace std;
#define int long long
signed main() {
    int t;
    cin>>t;
    while(t--){
        int n, p, r, k;
        cin>>n>>p>>r>>k;

        int lastuse =1;
        bool won = true;

        for(int i = 1; i <= n; i++){
            int a; 
            cin>>a;
            if(i - lastuse >= k){
                p += r;
                lastuse = i;
            }
            if(a > p){  
                won = false;
            }
            // cout<<p<<" "<<a<<"\n";
            p -= a;
        }

        if(won){
            cout<<"nah i'd win\n";
        }else{
            cout<<"nah i'd lose\n";
        }
    }
}