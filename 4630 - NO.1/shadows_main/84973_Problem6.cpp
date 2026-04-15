#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    if (!(T >= 1 && T <= 50)) {
        cout << "The value of T is greater than or equal to 1 and less than or equal to 50.";
        return -1;
    }
    while (T--) {
        int N;
        cin >> N;
        if (!(N >= 1 && N <= 1000)) {
            cout << "The value of N is greater than or equal to 1 and less than or equal to 1000";
            return -1;
        }
        vector<string> S1(N), S2(N);
        for (int i = 0; i < N; ++i) {
            cin >> S1[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> S2[i];
        }

        long long max_vol = 0, min_vol = 0;
        for (int i = 0; i < N; ++i) {
            // 统计当前行中#的数量
            int cnt1 = 0, cnt2 = 0;
            for (char c : S1[i]) if (c == '#') cnt1++;
            for (char c : S2[i]) if (c == '#') cnt2++;

            max_vol += 1LL * cnt1 * cnt2;
            min_vol += max(cnt1, cnt2);
        }

        cout << max_vol << " " << min_vol << "\n";
    }
    return 0;
}