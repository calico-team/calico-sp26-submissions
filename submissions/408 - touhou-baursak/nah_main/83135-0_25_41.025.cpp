#include <bits/stdc++.h>
using namespace std;

void setup(){

}
void solve(){
    int n;
    cin>>n;
    int p;
    cin>>p;
    int r;
    cin>>r;
    int k;
    cin>>k;
    vector<int> e(n);
    for (int&i:e){
        cin>>i;
    }
    int ck = k;
    int cp = p; //funny acronym yay!
    for (int i=0;i<n;i++){
        cp -= e[i];
        if (cp<0){
            cout<<"nah i'd lose\n";
            return;
        }
        ck--;
        if (ck==0){
            ck=k;
            cp+=r;
        }
    }
    cout<<"nah i'd win\n";



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