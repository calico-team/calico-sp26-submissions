#include <bits/stdc++.h>
using namespace std;
int T,L,W,E,R;
int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>L>>W>>E>>R;
        int C = 2*(L+W);
        int Num = C*R;
        cout<<E/Num<<endl;
    }
}