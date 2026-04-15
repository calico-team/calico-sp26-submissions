#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t;
    cout<<"enter value of t=";
    cin >> t;

    while (t--)
	 {
	 	int perimeter,electricity,lap;
        int l, w, e, r;
        cin>> l >> w >> e >> r; 
        perimeter = 2*(l + w);
        electricity=perimeter * r;
        lap = (e + electricity-1) /electricity;
        cout<< lap << endl; 
    }
    return 0;
}
