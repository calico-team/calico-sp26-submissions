#include<bits/stdc++.h>
using namespace std;

string censor_this_please(string s1, string s2){
    int f=0;
    string s3=s1;
    for(int i=0;i<(int)s1.size();i++){
        if(f<(int)s2.size() && s1[i]==s2[f]){
            s3[i]=s1[i];
            f++;
        } else {
            s3[i]='#';
        }
    }
    return s3;
}

void read_your_input(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<censor_this_please(s1,s2)<<"\n";
    }
}

int main(){
    read_your_input();
    return 0;
}
