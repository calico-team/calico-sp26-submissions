#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        
        vector<long long> c1(N, 0);
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            for (char c : s) {
                if (c == '#') {
                    c1[i]++;
                }
            }
        }
        
        vector<long long> c2(N, 0);
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            for (char c : s) {
                if (c == '#') {
                    c2[i]++;
                }
            }
        }
        
        long long maxV = 0;
        long long minV = 0;
        
        for (int i = 0; i < N; ++i) {
            maxV += c1[i] * c2[i];     
            minV += max(c1[i], c2[i]);      
        }
        
        cout << maxV << " " << minV << "\n";
    }
    return 0;
}