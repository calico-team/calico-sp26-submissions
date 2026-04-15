#include <iostream>
#include <string>

using namespace std;

int main() {
    int testCases;
    if (!(cin >> testCases)) return 0;

    while (testCases--) {
        string original, target;
        cin >> original >> target;

        string finalString = "";
        int targetPos = 0;

        for (int i = 0; i < original.length(); i++) {
            if (targetPos < target.length() && original[i] == target[targetPos]) {
                finalString += original[i];
                targetPos++;
            } else {
                finalString += '#';
            }
        }

        cout << finalString << endl;
    }

    return 0;
}