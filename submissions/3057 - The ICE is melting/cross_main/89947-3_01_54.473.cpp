// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

/*
 * Create an N x M grid such that every valid cross contains 0-4 exactly once.
 * 
 * N: number of rows in the grid
 * M: number of columns in the grid
 */

int main() {
    int T;

    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;

        //first row starts here
        cout << 0 << " "; 
        int counter = 1;
        int prevValue = 1;

        for (int j = 0; j < M - 2; j++) {
            cout << counter << " ";

            counter = (counter + 1) % 5;
        }

        cout << 0 << "\n";

        //next n rows
        for (int j=0; j < N-2; j++) {
            if ((((prevValue + 2) % 5)-1) >= 0) {
                counter = ((prevValue + 2) % 5)-1;
            } else {
                counter = 4;
            }

            for (int k = 0; k < M; k++) {
                cout << counter << " ";
                counter = (counter + 1) % 5;

                if (k == 2) {
                    prevValue = counter;
                }
            }

            cout << endl;
        }
        
        //final row
        cout << 0 << " "; 
        if ((((prevValue + 2) % 5)-2) >= 0) {
            counter = ((prevValue + 2) % 5)-2;
        } else {
            counter = 4;
        }

        for (int j = 0; j < M - 2; j++) {
            cout << counter << " ";

            counter = (counter + 1) % 5;
        }
        cout << 0 <<"\n";

    }
}
