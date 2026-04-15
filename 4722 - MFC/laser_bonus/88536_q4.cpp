#include <iostream>
#include <vector>

int main() {
    // gets the number of cases
    int cases{};
    std::cin >> cases;

    std::vector<int> answers = {};

    for (int i{}; i < cases; i++) {
        int K;
        int N;
        int M;
        int P;
        int Q;

        std::cin >> K;
        std::cin >> N;
        std::cin >> M;
        std::cin >> P;
        std::cin >> Q;


        N--; // x-coord
        M--; // y-coord

        std::vector<int> x_coord;
        std::vector<int> y_coord;
        

        for (int i{}; i < K; i++) {
            int x;
            int y;
            std::cin >> x >> y;
            x_coord.push_back(x);
            y_coord.push_back(y);
        }

        int c_x = x_coord[0];
        int c_y = y_coord[0];

        bool complete = 1;

        while (complete) {
            c_x += Q;
            c_y += P;

            while (c_x > N) {
                c_x -= (N + 1);
            }
            while (c_y > M) {
                c_y -= (M + 1);
            }

            for (int i{}; i < K; i++) {
                if (c_x == x_coord[i]) {
                    if (c_y == y_coord[i]) {
                        answers.push_back(i);
                        complete = 0;
                    }
                } 
            }
        }
    }

    for (int answer : answers) {
        std::cout << answer << '\n';
    }

    return 0;
        
}
