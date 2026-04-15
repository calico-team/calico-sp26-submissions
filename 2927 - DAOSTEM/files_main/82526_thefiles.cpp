#include <bits/stdc++.h>
using namespace std;
int main()
{
int T;
cin>>T;
while(T--){
    string str,target;
    cin>>str>>target;
    int id=0;
    for(int i=0;i<str.length();i++){
        if(id!=target.length()){
        if(target[id]==str[i]){
            cout<<str[i];
            id++;
        }else{
            cout<<"#";
        }
    }else{
        cout<<"#";
    }
    }cout<<endl;
}
    return 0;
}