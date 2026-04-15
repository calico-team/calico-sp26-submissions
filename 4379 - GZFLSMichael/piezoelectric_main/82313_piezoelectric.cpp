#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,L,W,E,R;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> L >> W >> E >> R;
        int P = 2*(L + W);
        int electricity = P * R;
        int laps = E/ electricity;
        cout << laps << endl;
    }
    return 0;
}