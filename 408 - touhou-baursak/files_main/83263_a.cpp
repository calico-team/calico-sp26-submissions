#include <bits/stdc++.h>
using namespace std;

void setup(){

}
void solve(){
    string s;
    string t;
    int cp=0;
    cin>>s>>t;
    for (char&i:s){
        if (cp!=t.size()){
            if (i!=t[cp]){
                i='#';
            }
            else{
                cp++;
            }
        }
        else{
            i='#';
        }
    }
    cout<<s<<"\n";
    //example 4 is fake news

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }

}
//HATSUNE MIKU WILL MAKE ME WIN CALICO