#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string solve(string a, string b) {
    string ans="";
    int ptr=0;
    for(int i=0;i<=a.length()-1;i++){
        if(a[i]==b[ptr]){
            ans+=a[i];
            ptr++;
            continue;
        }
        ans+='#';
    }
    return ans;
}
int main(){
    /*ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<"\n";
    }
}