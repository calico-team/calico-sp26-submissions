#include<bits/stdc++.h>
using namespace std;
int order[5] = {4, 1, 3, 0, 2};
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << (order[i%5]+j)%5 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}