
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ans;
        for(int i = 0; i<n; i++){
            int a;
            cin >> a;
            ans.push_back(a);
        }
        for(int i = 1; i<n-1; i++){
            if(ans[i]<ans[i-1] && ans[i]<ans[i+1]){
                ans[i]=min(ans[i-1], ans[i+1]);
            }
            if(ans[i]>ans[i-1] && ans[i]>ans[i+1]){
                ans[i]=max(ans[i-1], ans[i+1]);
            }
        }
        for(int i = 0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
