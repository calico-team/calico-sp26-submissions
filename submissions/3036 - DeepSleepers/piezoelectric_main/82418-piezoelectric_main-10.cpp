#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int l,w,needed,step; cin >> l >> w >> needed >> step;
        int total = 0;
        int num = 0;
        while(total<needed) {
            num++;
            total+=(2*l+2*w)*step;
        }
        cout << num << endl;   
    }
}
