#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */

string solve(int N, vector<string> S1, vector<string> S2) {
    int max_volume = 0;
    int min_volume = 0;
    for (int i = 0; i < N; i++) {
        max_volume += count(S1[i].begin(), S1[i].end(), '#') * count(S2[i].begin(), S2[i].end(), '#');
        min_volume += max(count(S1[i].begin(), S1[i].end(), '#'), count(S2[i].begin(), S2[i].end(), '#'));
    }
    return to_string(max_volume) + " " + to_string(min_volume);
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
        cout << solve(N, S1, S2) << '\n';
    }
}
