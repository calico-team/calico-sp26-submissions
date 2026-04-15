#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        string b;
        cin >> b;
        int idx = 0;
        string s2 = "";
        for(int i = 0; i < (int)b.size(); i++){
            while(idx < (int)a.size() && a[idx] != b[i]){
                s2 += '#';
                idx++;
            }
            s2 += b[i];
            idx++;
        }
        while(idx < (int)a.size()){
            s2 += '#';
            idx++;
        }
        cout << s2 << "\n";
    }
}