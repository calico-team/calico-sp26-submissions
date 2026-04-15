#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int L,W,E,R;
    int a,b;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> L >> W >> E >> R;
        b = (L+W);
        a = 2*R*b;
        cout << E/a<<'\n';
    }
    return 0;
}