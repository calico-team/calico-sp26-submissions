#include <iostream>
using namespace std;

int t, l, w, e, r, lap;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> l >> w >> e >> r;
        lap = (l+w)*2*r;
        cout << e/lap << '\n';
    }
}
