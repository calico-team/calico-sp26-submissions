#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    for (int i =0;i<T;i++){
        string A,B;
        cin>>A;
        cin>>B;
        for (int i =0;i<A.length();i++){
            if (A[i]==A[i+1])
                A[i]='#';
        }
        cout<<A<<endl;
    }
}