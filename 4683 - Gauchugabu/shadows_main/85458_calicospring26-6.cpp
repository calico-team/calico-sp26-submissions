// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<string> c1(n);
        vector<string> c2(n);
        for (int i = 0; i < n; i++){
            cin >> c1[i];
        }
        for (int i = 0; i < n; i++){
            cin >> c2[i];
        }
        int ma = 0;
        int mi = 0;
        vector<int> s1(n);
        vector<int> s2(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (c1[i][j] == '#') s1[i]++;
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (c2[i][j] == '#') s2[i]++;
            }
        }
        for (int i = 0; i < n; i++){
            mi += max(s1[i],s2[i]);
            ma += s1[i] * s2[i];
        }
        cout << ma << " " << mi << "\n";
    }
}
