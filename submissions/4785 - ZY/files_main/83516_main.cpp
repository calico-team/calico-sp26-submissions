//
//  main.cpp
//  测试II
//
//  Created by Kevin on 2024/12/8.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

string solve(string a, string b) {
    int place=0;
    string out;
    for (int i=0;i<(int)a.length();i++){
        if (a[i] == b[place]){out=out+a[i]; place++;}
        else{out=out+'#';}
    }
    return out;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}	
