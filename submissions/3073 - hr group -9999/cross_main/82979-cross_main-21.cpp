#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a, b;
    cin >> a >> b;
    int begin = 0;
    for(int i = 0; i < a; i++){
        int cur = begin;
        for(int j = 0; j < b; j++){
            cout << cur;
            if(j != b - 1){
                cout << " ";
            }
            cur++;
            if(cur == 5){
                cur = 0;
            }
        }
        begin += 2;
        if(begin >= 5){
            begin -= 5;
        }
        cout << endl;
    }
}
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}