#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    string masked = A;
    int seek_pos = 0;

    for (int walk_pos = 0; walk_pos < (int)A.size(); walk_pos++) {
        if (seek_pos < (int)B.size() && A[walk_pos] == B[seek_pos]) {
            seek_pos++;
        } else {
            masked[walk_pos] = '#';
        }
    }

    return masked;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int batch_count;
    cin >> batch_count;

    while (batch_count--) {
        string first_text, second_text;
        cin >> first_text >> second_text;
        cout << solve(first_text, second_text) << endl;
    }
}

