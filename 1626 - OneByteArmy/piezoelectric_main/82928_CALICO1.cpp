#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int l, w, e, r;
        cin >> l >> w >> e >> r;
        int perimeter = 2*(l+w);
        int steps = e/r;
        int laps = steps/perimeter;
        cout << laps << endl;
    }
}

