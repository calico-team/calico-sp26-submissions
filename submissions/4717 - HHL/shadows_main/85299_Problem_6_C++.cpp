#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<string> s1(n), s2(n);
        for (int i = 0; i < n; i++) cin >> s1[i];
        for (int i = 0; i < n; i++) cin >> s2[i];
        
        long long max_vol = 0, min_vol = 0;
        
        for (int z = 0; z < n; z++) {
            long long count1 = count(s1[z].begin(), s1[z].end(), '#');
            long long count2 = count(s2[z].begin(), s2[z].end(), '#');
            max_vol += count1 * count2;
            min_vol += max(count1, count2);
        }
        
        cout << max_vol << " " << min_vol << "\n";
    }
    return 0;
}
