#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<long long, long long> solve(int N, vector<string>& S1, vector<string>& S2) {
    long long max_vol = 0;
    long long min_vol = 0;

    for (int i = 0; i < N; i++) {
        long long count1 = 0;
        long long count2 = 0;
        
        for (int j = 0; j < N; j++) {
            if (S1[i][j] == '#') count1++;
            if (S2[i][j] == '#') count2++;
        }
        max_vol += (count1 * count2);
        min_vol += max(count1, count2);
    }

    return {max_vol, min_vol};
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<string> S1(N), S2(N);
        for (int i = 0; i < N; i++) cin >> S1[i];
        for (int i = 0; i < N; i++) cin >> S2[i];

        pair<long long, long long> ans = solve(N, S1, S2);
        cout << ans.first << " " << ans.second << "\n";
    }
}