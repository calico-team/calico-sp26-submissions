#include <iostream>
#include <string>
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
    // YOUR CODE HERE
    int s1h = 0;
    int s2h = 0;
    int s1b = 0;
    int s2b = 0;
    for (int i = 0; i<N; i++) {
      s1h += std::count(S1[i].begin(), S1[i].end(), '#');
      s1b += std::count(S1[i].begin(), S1[i].end(), '.');
      s2h += std::count(S2[i].begin(), S2[i].end(), '#');
      s2b += std::count(S2[i].begin(), S2[i].end(), '.');
    }
    if (s1h == 0 && s2h == 0) return "0 0";
    const unsigned int cube_max = s1h+s2h;
    const unsigned int cube_min = N - (s1b+s2b);
    string ret = to_string(cube_max) + " " + to_string(cube_min);
    return ret;
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
