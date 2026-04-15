#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int T;
int main() {
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        int bdx = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == B[bdx]) {
                bdx++;
            } else {
                A[i] = '#';
            }
        }
        cout << A << endl;
    }
}