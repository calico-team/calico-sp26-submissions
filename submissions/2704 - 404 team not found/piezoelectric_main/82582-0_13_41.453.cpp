#include <iostream>
using namespace std;
int main(){
    int t, l, w, e, r;
    cin >> t;
    for(int i = 0;i < t;i++){
        cin >> l;
        cin >> w;
        cin >> e;
        cin >> r;
        int perimeter = 2 * (l + w);
        int gen_per_lap = perimeter * r;
        int num_laps = e / gen_per_lap;
        cout << num_laps << endl;
    }
    return 0;
}