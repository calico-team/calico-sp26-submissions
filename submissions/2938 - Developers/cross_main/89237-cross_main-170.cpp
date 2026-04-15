#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int T;
    if (!(cin >> T)) return;
    
    while (T--) {
        int N;
        cin >> N;
        
        // Count the '#' for each row in S1
        vector<long long> u_counts(N);
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            long long count = 0;
            for (char ch : s) {
                if (ch == '#') count++;
            }
            u_counts[i] = count;
        }
        
        long long max_vol = 0;
        long long min_vol = 0;
        
        // Count the '#' for each row in S2 and calculate layer volumes
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            long long v_count = 0;
            for (char ch : s) {
                if (ch == '#') v_count++;
            }
            
            long long u_count = u_counts[i];
            
            max_vol += u_count * v_count;
            min_vol += max(u_count, v_count);
        }
        
        cout << max_vol << " " << min_vol << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
