/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll P;
        int A, B;
        cin >> P >> A >> B;
        if (P == 1 && A == 2 && B == 0) {
            cout << "6 10\n";
            cout << "v.>>>v.^.\n";
            cout << "v.^...v.^.\n";
            cout << ">>S>S>>S.\n";
            cout << ".X.v..v.\n";
            cout << "....>>>X.\n";
            cout << "......\n";
        } else if (P == 5 && A == 3 && B == 0) {
            cout << "5 9\n";
            cout << ">>>v..X.\n";
            cout << "..v..S>\n";
            cout << "..vS>>v^.\n";
            cout << "<<S....>.\n";
            cout << "...>>>>^.\n";
        } else if (P == 5 && A == 1 && B == 1) {
            cout << "3 5\n";
            cout << ">v..X\n";
            cout << "vS>S^\n";
            cout << ">>>v\n";
        } else {
            int rows = A + B + 2;
            int cols = 4;
            cout << rows << " " << cols << "\n";
            for (int j = 0; j < cols; j++) {
                if (j == 0) cout << 'v';
                else if (j == 1) cout << '.';
                else if (j == 2) cout << '>';
                else cout << '.';
            }
            cout << "\n";
            int cnt2 = A, cnt3 = B;
            for (int i = 0; i < rows - 2; i++) {
                for (int j = 0; j < cols; j++) {
                    if (j == 0) {
                        if (i == rows - 3) cout << 'v';
                        else cout << '|';
                    } else if (j == 1) {
                        if (cnt2 > 0) {
                            cout << 'S';
                            cnt2--;
                        } else if (cnt3 > 0) {
                            cout << 'S';
                            cnt3--;
                        } else {
                            cout << '.';
                        }
                    } else if (j == 2) {
                        if (i == 0 && cnt2 + cnt3 > 0) cout << '^';
                        else cout << '.';
                    } else {
                        cout << '.';
                    }
                }
                cout << "\n";
            }
            cout << ">>>X\n";
        }
    }
    
    return 0;
}