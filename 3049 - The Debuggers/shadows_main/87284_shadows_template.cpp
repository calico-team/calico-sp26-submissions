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
pair<int, int> solve(int N, vector<string> S1, vector<string> S2) {
    // YOUR CODE HERE
    long long maxx = 0;
    long long minn = 0;

    for (int i = 0; i < N; i++) {
        int number_of_block_in_first = 0;
        int number_of_block_in_second = 0;
        
        for (char c : S1[i]) {
            if (c == '#') {
                number_of_block_in_first++;
            }
        }

        for (char c : S2[i]) {
            if (c == '#') {
                number_of_block_in_second++;
            }
        }

        maxx += number_of_block_in_first * number_of_block_in_second;
        minn += max(number_of_block_in_first, number_of_block_in_second);
    }
    return make_pair(maxx, minn);
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

        auto a = solve(N, S1, S2);
        cout << a.first << " " << a.second << '\n';
    }
}
