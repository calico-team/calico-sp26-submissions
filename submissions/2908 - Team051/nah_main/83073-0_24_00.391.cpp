#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++){ 
            cin >> a[i];
        }
        bool gane = true;
        for (int i = 0; i < N; i++){
            if (P < a[i]){
                gane = false;
                break;
            }
            P = P - a[i];
            if ((i + 1) % K == 0){
                P = P + R;
            }
        }
        if (gane){
            cout << "nah i'd win" << '\n';
        }
        else{
            cout << "nah i'd lose" << '\n';
        }
    }
}