#include<iostream>
#include<string>
using namespace std;

string ans(string a, string b){
    int i=0;
    for(int j=0;j<b.length();j++){
        while(a[i]!=b[j]){
            a[i]='#';
            i++;
        }
        i++;
        //cout<<a<<endl;
    }
    /*while(i<a.length() && a[i]!=b[b.length()-1]){
        a[i]='#';
        i++;
    }*/
    i=a.length()-1;
    for(int j=b.length()-1;j>=0;j--){
        while(a[i]!=b[j]){
            a[i]='#';
            i--;
        }
        i--;
        //cout<<a<<endl;
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