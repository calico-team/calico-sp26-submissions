#include <iostream>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int totalCurses, power, restore, afterCurses;
        cin >> totalCurses >> power >> restore >> afterCurses;

        int dylan_power = power;

        bool lost = false;

        for (int index = 1; index <= totalCurses; index++) {
            int cursePower;
            cin >> cursePower;

            if (dylan_power < cursePower) {
                cout << "nah i'd lose" << endl;
                lost = true;
                for (int skip = index + 1; skip <= totalCurses; skip++) cin >> cursePower;
                break;
            }

            dylan_power -= cursePower;

            if (index % afterCurses == 0) {
                dylan_power += restore;
            }
        }

        if (!lost) {
            cout << "nah i'd win" << endl;
        }
    }

    return 0;
}