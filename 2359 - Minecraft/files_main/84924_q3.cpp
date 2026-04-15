#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        string a, b;
        cin >> a >> b;
        string result = "";
        int j = 0;  
        for(int i = 0; i < a.size(); i++) {
            if(j < b.size() && a[i] == b[j]) {
                result += a[i];
                j++;  
            } else {
                result += '#';
            }
        }
        cout << result << endl;
    }
    return 0;
}