#include <iostream>

int main() {
	int numTestCases;
	std::cin >> numTestCases;

	for (int i {0}; i < numTestCases; i++) {
		int numCurses, power, RCT, RCTcurses;
		std::cin >> numCurses >> power >> RCT >> RCTcurses;

		bool dead = false;
		int cursesKilled = 0;
		for (int j {0}; j < numCurses; j++) {
			int cursePower;
			std::cin >> cursePower;
			power -= cursePower;

			if (power < 0) {
				dead = true;
			}

			cursesKilled++;
			if (cursesKilled == RCTcurses) {
				cursesKilled = 0;
				power += RCT;
			}
		}
		if (dead) {
			std::cout << "nah i'd lose" << std::endl;
			continue;
		}
		std::cout << "nah i'd win" << std::endl;
	}
	return 0;
}