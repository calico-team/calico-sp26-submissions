#include <iostream>
#include <vector>

int main() {
    // gets the number of cases
    int cases{};
    std::cin >> cases;

    std::vector<bool> answers = {};

    for (int i{}; i < cases; i++) {

        std::vector<int> curses = {};

        int N;
        int P;
        int R;
        int K;

        std::cin >> N;
        std::cin >> P;
        std::cin >> R;
        std::cin >> K;

        int total{};

        for (int i{}; i < N; i++) {
            int curse;
            std::cin >> curse;

            curses.push_back(curse);
            total += curse;
        }

        // if the total of the curses if less than the power
        // just return he'd win
        if (total < P) {
            answers.push_back(1);
        }
        
        // else, model the battle here

        int defeated{};
        bool won = 1;

        for (int curse : curses) {

            // check if he can heal himself
            if (defeated == K) {
                P += R;
                defeated = 0;
            }

            // else, just do the battle
            P -= curse;
            defeated += 1;

            // if he dies
            if (P < 0) {

                // lost the battle
                won = 0;

                // end the battle
                break;
            }

        }

        // if he lost, won = 0, else (meaning he won), 
        // won = 1
        answers.push_back(won);

    }


    for (bool answer : answers) {
        if (answer == 1) {
            std::cout << "nah i'd win\n";
        } else {
            std::cout << "nah i'd lose\n";
        }
    }

    return 0;

}
