#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vector<string> S1(n), S2(n);
        for(int i = 0; i < n; i++) cin >> S1[i];
        for(int i = 0; i < n; i++) cin >> S2[i];
        long long max_vol = 0, min_vol = 0;
        for(int i = 0; i < n; i++) {  
            int a = 0, b = 0;
            for(int j = 0; j < n; j++) {
                if(S1[i][j] == '#') a++; 
                if(S2[i][j] == '#') b++;  
            }
            max_vol += 1LL * a * b;     
            min_vol += max(a, b);       
        }
        cout << max_vol << " " << min_vol << endl;
    }
    return 0;
}