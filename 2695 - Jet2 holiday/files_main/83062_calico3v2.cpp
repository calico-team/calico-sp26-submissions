#include <bits/stdc++.h>
using namespace std;

string turn_A(const string& A, const string& B) {
    string result;
    int j=0;
    for(char yyc:A){
        if(j < B.length()&& yyc == B[j]){
            result +=yyc;
            j++;
        }else result=result +'#';
    }
    return result;
}



int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string a,b;
        cin>>a>>b;
        cout<<turn_A(a,b)<<endl;
    }
    
}