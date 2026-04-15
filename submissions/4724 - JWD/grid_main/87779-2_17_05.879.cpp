#include <iostream>
using namespace std;
int t, x[10005];
int main()
{
    cin >> t;
    while (t--) {
        int n; cin >> n; 
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (n == 1)
			cout << x[1] << '\n';
		if (n == 2)
			cout << x[1] << ' ' << x[1] << '\n';
		if (n == 3) {
			if (x[1] == x[2] || x[1] == x[3]) cout << x[1] << ' ' << x[1] << ' ' << x[1] << '\n';
			else if (x[2] == x[3]) cout << x[2] << ' ' << x[2] << ' ' << x[2] << '\n';
			else cout << x[1] << ' ' << x[2] << ' ' << x[3] << '\n';
		}
		
    }
    return 0;
}