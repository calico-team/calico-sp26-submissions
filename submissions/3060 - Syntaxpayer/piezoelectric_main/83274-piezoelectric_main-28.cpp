#include <iostream>
using namespace std;

int main(){
    cout << "Enter number of testcases to be runned: " << endl;
    int T;
    cin >> T;


    while (T--){
        int L, W, E, R;
        cin >> L >> W >> E >> R;

        int perimeter = 2*(L + W);
        int elec_per_lap = R * perimeter;
        int total_laps = E / elec_per_lap;
        cout << total_laps << endl;
    }
    return 0;
}