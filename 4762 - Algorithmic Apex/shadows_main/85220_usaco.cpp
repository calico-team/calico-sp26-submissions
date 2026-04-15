#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> s1(n);
        vector<string> s2(n);
        for(int i = 0; i < n; i++) cin >> s1[i];
        for(int i = 0; i < n;i++) cin>> s2[i];
        ll maxv = 0;
        ll minv = 0;
        for(int i = 0; i < n; i++){
            int x=0, y =0;
            for(int j = 0; j < n; j++) if(s1[i][j] =='#') x++;
            for(int k = 0; k < n; k++) if(s2[i][k] =='#') y++;
            maxv+= (ll)x * y;
            minv +=max(x, y);
        }
        cout << maxv << " " << minv << "\n";
    }
}