#include <iostream>

using namespace std;

/**
 * Return the total number of tiles mycelium will ever occupy.
 *
 * X_G: x-coordinate of grass starting position
 * Y_G: y-coordinate of grass starting position
 * X_M: x-coordinate of mycelium starting position
 * Y_M: y-coordinate of mycelium starting position
 */
int solve(int X_G, int Y_G, int X_M, int Y_M) {
    int count = 0;
    int R = 200;
    
    for (int x = X_M - R; x <= X_M + R; x++) {
        for (int y = Y_M - R; y <= Y_M + R; y++) {
            int distM = abs(x - X_M) + abs(y - Y_M);
            int distG = abs(x - X_G) + abs(y - Y_G);
            if (7 * distM < 2 * distG) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int X_G, Y_G, X_M, Y_M;
        cin >> X_G >> Y_G >> X_M >> Y_M;
        cout << solve(X_G, Y_G, X_M, Y_M) << '\n';
    }
}
