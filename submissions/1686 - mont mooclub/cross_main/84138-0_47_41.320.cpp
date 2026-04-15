// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t; cin >> t;
    for (int k = 0; k<t; k++){
        long long m, n; cin >> m >> n;
        long long currstart = 0;
        for (int i = 0; i<m; i++){
            currstart+=2;
            long long cs = currstart%5;
            for (int j = 0; j<n-1; j++){
                cout << cs << " ";
                cs+=1;
                cs = cs%5;
            }
            cout << cs << endl;
        }
    }
}
