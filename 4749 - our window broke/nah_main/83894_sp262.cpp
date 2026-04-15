#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,p,r,k;
        cin >> n >> p >> r >> k;
        vector<int> e(n);
        int i=0;
        bool w=true;
        while(i<n){
            cin  >> e[i];
            if(p-e[i] >= 0){
                p -= e[i];
            }else{
                w = false;
            }
            i++;
            if(i%k==0){
                p += r;
            }
        }
        cout << (w ? "nah i'd win" : "nah i'd lose");
    }
}