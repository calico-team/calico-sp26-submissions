#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        string A, B;
        cin >> A >> B;
        int j = 0;
        for(int i = 0; i < A.length(); i++){
            if(j < B.length() && B[j] == A[i]){
                j++;
            }else{
                A[i] = '#';
            }
        }
        cout << A << endl;
    }
}