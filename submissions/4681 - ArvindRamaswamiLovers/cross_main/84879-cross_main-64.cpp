#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                cout << (2*r + c) % 5;
                if(c < m-1) cout << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}