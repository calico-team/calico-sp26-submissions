#include <bits/stdc++.h>
using namespace std;




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n,p,r,k;
        cin>>n>>p>>r>>k ;

        vector<int> E(N);
        for (int i = 0; i < N; i++)cin>>E[i];

        int dylan_power = P;
        int count = 0;
        bool win = true;

        for (int i = 0; i < N; i++) {
            dylan_power -= E[i];
            if (dylan_power < 0) {
                win = false;
                break;
            }

            count++;

            if (count==K) {
                dylan_power += R;
                count = 0;
            }
        }

        if (win){
            cout << "nah i'd win\n";

        }
        else{
            cout << "nah i'd lose\n";

        }
       
        
    }

    
}