#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, m, P, R;
        cin >> n >> m >> P >> R;
        cout << (P/(R*2*(n+m))) << '\n';
    }
    return 0;
}