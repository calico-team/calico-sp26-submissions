// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t; cin >> t;
    for (int l = 0; l<t; l++){
        bool tf = true;
        long long cc, p, amt, k; cin >> cc >> p >> amt >> k;
        for (int i = 0; i<cc; i++){
            long long c; cin >> c;
            if (p < c){
                tf = false;
            }
            else{
                p-=c;
                if ((i+1) % k == 0){
                    p += amt;
                }
            }
        }
        if (tf){
            cout << "nah i'd win" << endl;
        }
        else{
            cout << "nah i'd lose" << endl;
        }
    }
}
