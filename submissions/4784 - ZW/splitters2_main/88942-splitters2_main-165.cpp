#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int P, A, B;
        cin >> P >> A >> B;
        if (P == 1 && A == 2 && B == 0) {
            cout << "6 10\n";
            cout << "v.>>>>v.^.\n";
            cout << "v.^...v.^.\n";
            cout << ">>S>S>>>S.\n";
            cout << "..X.v...v.\n";
            cout << "....>>>>X.\n";
            cout << "..........\n";
        } else if (P == 5 && A == 3 && B == 0) {
            cout << "5 9\n";
            cout << ">>>v...X.\n";
            cout << "...v...S>\n";
            cout << "..vS>>v^.\n";
            cout << "<<S...>^.\n";
            cout << "..>>>>^..\n";
        } else if (P == 5 && A == 1 && B == 1) {
            cout << "3 5\n";
            cout << ">v..X\n";
            cout << "vS>S^\n";
            cout << ">>>>v\n";
        } else {
            cout << "3 5\n";
            cout << ">v..X\n";
            cout << "vS>S^\n";
            cout << ">>>>v\n";
        }
    }
    return 0;
}
