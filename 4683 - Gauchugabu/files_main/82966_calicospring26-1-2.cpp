// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--){
        string s, g; cin >> s >> g;
        int ind = 0;
        for (int i = 0; i < s.size(); i++){
            if (ind < g.size()){
                if (s[i] == g[ind]){
                    ind++;
                }
                else{
                    s[i] = '#';
                }
            }
            else{
                s[i] = '#';
            }
            
        }
        cout << s << "\n";
    }
}
