#include <bits/stdc++.h>
using namespace std;

int main() {
    // ifstream cin("input");
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<string> a(n);
        vector<string> b(n);
        
        long long mini = 0;
        long long maxi = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        for (int i = 0; i < n; i++) {
            int aCount = 0;
            int bCount = 0;
            for (int j = 0; j < n; j++) {
                aCount += (a[i][j] == '#');
                bCount += (b[i][j] == '#');
            }
            maxi += aCount * bCount;
            mini += max(aCount, bCount);
        }
        
        cout << maxi << ' ' << mini << endl;
    }
}