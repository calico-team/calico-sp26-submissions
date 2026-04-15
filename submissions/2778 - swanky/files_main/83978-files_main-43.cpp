#include<iostream>
#include<string>
using namespace std;

string ans(string a, string b){
    int i=0;
    for(int j=0;j<b.length();j++){
        //cout<<b[j]<<": ";
        while(a[i]!=b[j]){
            //cout<<a[i]<<" ";
            a[i]='#';
            i++;
        }
        i++;
    }
    while(i<a.length()){
        a[i]='#';
        i++;
    }
    return a;
}

int main(){
    int test;
    cin>>test;
    for(int t=0; t<test;t++){
        string a,b;
        cin>>a>>b;
        cout<<ans(a,b)<<endl;
    }
}