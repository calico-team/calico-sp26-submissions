#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;cin>>T;

    while (T--) {
        int numR, numC;cin>>numR>>numC;

        for (int r=0; r<numR ; r++) {
            for (int c=0; c<numC; c++) {
                cout << ' ' << (r+2*c)%5;
            }
            cout << '\n';
        }
    }
}
