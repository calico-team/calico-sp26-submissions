#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        vector<string> v2(n);
        for(int i = 0; i < n; i++){
            cin >> v2[i];
        }
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 0; i < n; i++){
            int val = 0;
            int val2 = 0;
            for(int j = 0; j < n; j++){
                if(v[i][j] == '#'){
                    val++;
                }
                if(v2[i][j] == '#'){
                    val2++;
                }
            }
            ans1 += val * val2;
            ans2 += max(val, val2);
        }
        cout << ans1 << " " << ans2 << "\n";
    }
}