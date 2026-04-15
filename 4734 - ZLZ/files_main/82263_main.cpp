#include <iostream>
using namespace std;

string censor_this_please(const string& A, const string& B) {
    int i = 0;
    string res;
    for (char c : A) {
        if (i < (int)B.size() && c == B[i]) {
            res.push_back(c);
            i++;
        } else {
            res.push_back('#');
        }
    }
    return res;
}

void read_your_input() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        string A, B;
        cin >> A >> B;
        cout << censor_this_please(A, B) << '\n';
    }
}

int main() {
    read_your_input();
    return 0;
}
