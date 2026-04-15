#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        string A, B;
        cin >> A >> B;
        
        string result = A;
        int j = 0;
        for (int i = 0; i < (int)A.size(); i++) {
            if (j < (int)B.size() && A[i] == B[j]) {
                j++;
            } else {
                result[i] = '#';
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}