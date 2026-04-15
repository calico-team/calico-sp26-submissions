#include <iostream>
#include <string>

using namespace std;
void solve() {
    string A, B;
    cin >> A >> B;   
    int j= 0; 
    for (int i = 0; i<A.length(); i++) {
        if (j < B.length() && A[i]==B[j]) {
            j++; 
        } else {
            A[i] = '#';
        }
    }
    cout << A << "\n";
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}