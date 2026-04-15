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

        vector<int> E(n);
        for (int i = 0; i < n; i++)cin>>E[i];

        int dylan_power = p;
        int count = 0;
        bool win = true;

        for (int i = 0; i < n; i++) {
            dylan_power -= E[i];
            if (dylan_power < 0) {
                win = false;
                break;
            }

            count++;

            if (count==k) {
                dylan_power += r;
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