#include <iostream>
#include <vector>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
void solve(int N, vector<string> S1, vector<string> S2) {
    int min1 = 0, max1 = 0;
    for (int i = 0; i < N; i ++) {
        int cnt1=0, cnt2=0;
        for (int j =0; j < N; j ++) {

            if (S1[i][j] == '#') {
                cnt1++;
            }
            if (S2[i][j] == '#') {
                cnt2++;
            }            
        }
        max1 += cnt1*cnt2;
        min1 += max(cnt1, cnt2);
        
    }
    cout << max1 << ' '<< min1;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<string> S1(N);
        for (int i = 0; i < N; i++) {
            cin >> S1[i];
        }
        vector<string> S2(N);
        for (int i = 0; i < N; i++) {
            cin >> S2[i];
        }
        solve(N, S1, S2);
        cout << '\n';
    }
}
