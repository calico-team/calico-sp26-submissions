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
string solve(int N, vector<string> S1, vector<string> S2) {
    // YOUR CODE HERE
    int mn = 0, mx = 0;
    string ans;
    vector<int> vec1(N, 0), vec2(N, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S1[i][j] == '#') {
                vec1[i]++;
            }
            if(S2[i][j] == '#') {
                vec2[i]++;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        mn += max(vec1[i], vec2[i]);
    }
    for(int i = 0; i < N; i++) {
        mx += vec1[i] * vec2[i];
    }


    ans = to_string(mx);
    ans += ' ';
    ans += to_string(mn);
    return ans;
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
