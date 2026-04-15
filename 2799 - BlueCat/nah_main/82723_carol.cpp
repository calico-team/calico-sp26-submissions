#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n,p,r,k;
        cin>>n>>p>>r>>k;

        vector<int> e(n);
        for(int i=0;i<n;i++)cin>>e[i];

        int power=p;
        bool win=true;

        for(int i=0;i<n;i++){
            power-=e[i];

            if(power<0){
                win=false;
                break;
            }

            if((i+1)%k==0){
                power+=r;
            }
        }

        if(win)cout<<"nah i'd win\n";
        else cout<<"nah i'd lose\n";
    }

    return 0;
}