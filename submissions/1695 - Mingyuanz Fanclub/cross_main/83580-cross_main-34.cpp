#include <bits/stdc++.h>
using namespace std;
#define pii array<int,2>
#define tii array<int,3>
void think(){
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i%3 == 0){
                cout << "0 ";
            }else if(i%3 == 2){
                cout << "4 ";
            }else{
                cout << (j%3) + 1 << ' ';
            }
        }
        cout << '\n';
    }
}
int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--){
        think();
    }
}