#include <iostream>
using namespace std;
int main() {
    int x;
    cin>> x;
    while (x--){
        int L,W, E,R;
        cin >> L >>W>> E >> R;
        int perimeter = 2 * (L + W);
        int electricityperlap = perimeter *R;
        int laps= E /electricityperlap;
        cout <<laps<< endl;
    }
    return 0;
}