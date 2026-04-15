#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,p,r,k;
        cin>>n>>p>>r>>k;
        vector<int> v(n);
        int sum = 0, val;
        for(int i=0;i<n;i++){
            cin >> val; v[i]=val;
            sum+=v[i];
        }
        if(sum<p) {cout << "nah i'd win" << endl; continue;}
        bool win=true;
        int numCurses=0;
        for(int i=0;i<n;i++){
            p-=v[i];
            numCurses++;

            if(p<0) {win=false; break;}

            if(numCurses==k){
                p+=r;
                numCurses=0;
            }
        }
    
        if(win) cout<<"nah i'd win"<< endl;
        else cout<<"nah i'd lose"<<endl;
        
    }
}