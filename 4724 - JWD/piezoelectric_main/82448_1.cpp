#include <iostream>
using namespace std;
int t;
int main()
{
    cin >> t;
    while (t--) {
        int h, l, e, r; cin >> h >> l >> e >> r;
        cout << e/(h+l)/2/r;
    }
    return 0;
}