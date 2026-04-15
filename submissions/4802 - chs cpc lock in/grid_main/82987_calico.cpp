
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ans(n);
        if(n==1){
            cin >> ans[0];
            cout << ans[0] <<" \n";
        }
        if(n==2){
            cin >> ans[0] >> ans[1];
            cout << ans[0] << " " << ans[1] << " \n";
        }
        if(n==3){
            cin >> ans[0] >> ans[1] >> ans[2];
            sort(ans.begin(), ans.end());
            for(int i = 0; i<3; i++){
                cout << ans[1] << " ";
            }
            cout << "\n";
        }
    }
}
