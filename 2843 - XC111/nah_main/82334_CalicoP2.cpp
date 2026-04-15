#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, p, r, k;
        cin >> n >> p >> r >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int cur = p;
        bool ans = true;
        int tempk = k;
        for(int i = 1; i <= n; i++){
            cur -= a[i];
            if(cur < 0){
                ans = false;
                break;
            }
            tempk--;
            if(tempk == 0){
                cur += r;
                tempk = k;
            }
        }
        if(ans == true){
            cout << "nah i'd win\n";
        }else{
            cout << "nah i'd lose\n";
        }
    }
    return 0;
}