#include <iostream>
#include <string>
#include <vector>

int main() {
    // gets the number of cases
    int cases{};
    std::cin >> cases;

    std::vector<std::string> answers = {};

    for (int i{}; i < cases; i++) {

        std::string A;
        std::string B;

        std::cin >> A;
        std::cin >> B;

        // get the length of B, then decrease it for indexing
        int length = B.size() - 1;
        int location{0};

        std::string output = "";

        // build A one letter at a time
        for (char letter : A) {

            if (letter == B.at(location)) {
                output += letter;
                location++;
                if (location > length) {
                    break;
                }
            } else {
                output += '#';
            }

        }

        answers.push_back(output);
    }

    for (std::string answer : answers) {
        std::cout << answer << '\n';
    }

    return 0;
        
}
