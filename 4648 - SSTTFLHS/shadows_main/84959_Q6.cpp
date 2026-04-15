#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
string solve(int N, vector<string> S1, vector<string> S2) {
    long long max_volume = 0;
    long long min_volume = 0;
    for (int z = 0; z < N; z++) {
        int a = 0; 
        int b = 0;
        for (int i = 0; i < N; i++) {
            if (S1[z][i] == '#') {
                a++;
            }
            if (S2[z][i] == '#') {
                b++;
            }
        }
        max_volume += 1LL * a * b;
        if (a > 0 || b > 0) {
            min_volume += max(a, b);
        }
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
