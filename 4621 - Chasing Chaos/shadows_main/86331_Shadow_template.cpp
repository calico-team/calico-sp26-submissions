#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve(int N, vector<string> S1, vector<string> S2) {
    long long biggest_volume = 0;
    long long smallest_volume = 0;

    for (int layer = 0; layer < N; layer++) {
        int left_hits = 0;
        int right_hits = 0;

        for (int a = 0; a < N; a++) {
            if (S1[layer][a] == '#') left_hits++;
            if (S2[layer][a] == '#') right_hits++;
        }

        biggest_volume += 1LL * left_hits * right_hits;
        smallest_volume += max(left_hits, right_hits);
    }

    return to_string(biggest_volume) + " " + to_string(smallest_volume);
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<string> S1(N);
        for (int j = 0; j < N; j++) {
            cin >> S1[j];
        }
        vector<string> S2(N);
        for (int j = 0; j < N; j++) {
            cin >> S2[j];
        }
        cout << solve(N, S1, S2) << '\n';
    }
}