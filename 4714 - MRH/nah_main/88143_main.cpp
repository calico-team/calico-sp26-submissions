#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll e[10005];
int main(){
    ll t, n, p, r, k, i, c=0, j, c1=0, c2=0;
    cin>>t;
    for(i=1; i<=t; i++){
        cin>>n>>p>>r>>k;
        for(j=1; j<=n; j++){
            cin>>e[j];
            c+=e[j];
            c1++;
        }
        if(p>=c){
            cout<<"nah i'd win"<<endl;
        }else{
            for(j=1; j<=k; j++){
                c2+=e[j];
            }
            if(c1>=k&&p>=c2&&k>1){
                c1/=k;
                r*=c1;
                p+=r;
                if(p>=c){
                    cout<<"nah i'd win"<<endl;
                }else{
                    cout<<"nah i'd lose"<<endl;
                }
            }else if(k=1){
                p+=r;
                if(p>=c){
                    cout<<"nah i'd win"<<endl;
                }else{
                    cout<<"nah i'd lose"<<endl;
                }
            }
        }
        c1=0;
        c=0;
    }
    return 0;
}
