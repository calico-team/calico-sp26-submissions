#include <iostream>
#include <vector>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int size;
        cin >> size;

        vector<long long> topRow(size);

        // input
        for (int i = 0; i < size; i++) {
            cin >> topRow[i];
        }

        // output (same values as top row)
        for (int i = 0; i < size; i++) {
            cout << topRow[i];

            if (i != size - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}