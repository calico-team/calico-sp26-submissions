#include<iostream>
#include<string>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        string A, B;
        cin >> A >> B;

        int j = 0;
        string result = "";

        for(int i = 0; i < A.size(); i++){
            if(j < B.size() && A[i] == B[j]){
                result += A[i];
                j++;
            } else {
                result += '#';
            }
        }

        cout << result << "\n";
    }

    return 0;
}
