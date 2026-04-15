#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--)
{
	int perimeter,electricity,laps;
        int l,w,e,r;
        cin >> l >> w >> e >> r;
        perimeter=2*(l+w);
        electricity = perimeter*r;
        laps=e/electricity;
         cout<<laps << "\n";
    }
        return 0;
}
