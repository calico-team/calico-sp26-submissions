#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        string obj; cin>>obj;
        set<int>pos;
        int n=s.size();
        int idx=0;
        for(int i=0;i<n;i++){
            if(idx>=obj.size()) break;
            if(obj[idx]==s[i]){
                idx++;
                pos.insert(i);
            }
        } 
        for(int i=0;i<n;i++){
            if(pos.count(i)) cout<<s[i];
            else cout<<"#";
        }
        cout<<endl;
    }

}
