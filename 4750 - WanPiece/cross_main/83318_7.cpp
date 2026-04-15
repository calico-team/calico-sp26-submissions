#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){

    int n, m;
    cin >> n >> m;

    vector<int> s = {0, 2, 4, 1, 3};

    for(int i = 0; i < n; i++){
        int curr = s[(i % 5)];
        for(int j = 0; j < m; j++){
            cout << curr << ' ';
            curr++;
            curr %= 5;
        }
        cout << endl;
    }

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;
    cin >> tc;
    while(tc--) solve();

}