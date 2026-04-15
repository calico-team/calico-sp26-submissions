#include <bits/stdc++.h>
using namespace std;

/*
 * M: number of rows in the lecture hall
 * N: number of columns in the lecture hall
 * K: number of friends who need seats
 * GRID: vector of M strings of length N; '#' is a blocked seat, '-' is an empty seat
 *
 * Return a vector of K (row, col) pairs for the chosen seats.
 */
vector<pair<int, int>> solve(int M, int N, int K, vector<string>& GRID) {
    struct Seat {
        int row;
        int col;
        int sum;
        int diff;
    };

    vector<Seat> seats;
    vector<vector<int>> bySum(M + N - 1);

    int shift = N - 1;
    int maxCoord = M + N - 2;

    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            if (GRID[row][col] == '-') {
                int sum = row + col;
                int diff = row - col + shift;
                int idx = (int)seats.size();
                seats.push_back({row, col, sum, diff});
                bySum[sum].push_back(idx);
            }
        }
    }

    auto findWindow = [&](int dist, int& bestSum, int& bestDiff) -> bool {
        vector<int> countDiff(maxCoord + 1, 0);
        int rightSum = -1;

        for (int leftSum = 0; leftSum <= maxCoord; leftSum++) {
            while (rightSum + 1 <= maxCoord && rightSum + 1 <= leftSum + dist) {
                rightSum++;
                for (int idx : bySum[rightSum]) {
                    countDiff[seats[idx].diff]++;
                }
            }

            int inBox = 0;
            for (int leftDiff = 0; leftDiff <= maxCoord; leftDiff++) {
                inBox += countDiff[leftDiff];
                if (leftDiff > dist) {
                    inBox -= countDiff[leftDiff - dist - 1];
                }
                if (inBox >= K) {
                    bestSum = leftSum;
                    bestDiff = leftDiff - dist;
                    return true;
                }
            }

            for (int idx : bySum[leftSum]) {
                countDiff[seats[idx].diff]--;
            }
        }

        return false;
    };

    int low = 0;
    int high = M + N;
    while (low < high) {
        int mid = (low + high) / 2;
        int boxSum, boxDiff;
        if (findWindow(mid, boxSum, boxDiff)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    int bestSum, bestDiff;
    findWindow(low, bestSum, bestDiff);

    vector<pair<int, int>> answer;
    for (const auto& seat : seats) {
        if (seat.sum >= bestSum && seat.sum <= bestSum + low &&
            seat.diff >= bestDiff && seat.diff <= bestDiff + low) {
            answer.push_back({seat.row, seat.col});
            if ((int)answer.size() == K) {
                break;
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        vector<string> GRID(M);
        for (int i = 0; i < M; i++) {
            cin >> GRID[i];
        }
        vector<pair<int, int>> result = solve(M, N, K, GRID);
        for (auto& p : result) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}