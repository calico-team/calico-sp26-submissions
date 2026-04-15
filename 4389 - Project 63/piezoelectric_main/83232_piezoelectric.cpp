#include <iostream>
using namespace std;

int main(){
    int L,W,X,R,E;
    cin>>X;
    for (int i =0;i<X;i++){
        cin>>L>>W>>E>>R;
        int perimeter = 2*(L+W);
        int output = E/(perimeter*R);
        cout<<output<<endl;
    }
}