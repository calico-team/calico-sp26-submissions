#include <iostream>
#include <string>
using namespace std;
int main() {
    int x;
    cin>>x;
    while(x--) {
        string A, B;
        cin >> A>> B;
        string result= A;
        int j=0;
        for (int i= 0;i< A.size(); i++){
            if(j <B.size()&& A[i]== B[j]) {
                j++;
            } else{
                result[i] ='#';
            }
        }
        cout<<result <<endl;
    }
    return 0;
}