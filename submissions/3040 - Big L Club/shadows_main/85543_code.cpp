#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<vector<bool>> a(n,vector<bool>(n)),b(n,vector<bool>(n));

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        char c; cin >> c;
        if(c=='#') a[i][j] = true;
        else a[i][j] = false;
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        char c; cin >> c;
        if(c=='#') b[i][j] = true;
        else b[i][j] = false;
    }

    int mnAns = 0;
    for(int i = 0; i < n; i++) {
        int cnt1 = 0, cnt2 = 0;
        for(int j = 0; j < n; j++) {
            cnt1 += a[i][j];
            cnt2 += b[i][j];
        }
        mnAns += max(cnt1,cnt2);
    }

    int mxAns = n*n*n;

    vector<vector<int>> notGood(n,vector<int>(n,0));
    for(int i = 0; i < n; i++) {
        reverse(b[i].begin(),b[i].end());
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!a[i][j]) {
                notGood[i][j]++;
                mxAns -= n;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int removed = 0;
        for(int j = 0; j < n; j++) {
            if(notGood[i][j]==1) removed++;
        }
  
        for(int j = 0; j < n; j++) {
            if(!b[i][j]) {
                mxAns -= n;
                if(removed) mxAns+=removed;
            }
        }
    }



    cout << mxAns << " " << mnAns << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        solve();
    }
} 
