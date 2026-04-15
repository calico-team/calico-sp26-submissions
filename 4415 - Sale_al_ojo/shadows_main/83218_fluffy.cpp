#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string>A(n);
        for(int i=0;i<n;i++) cin>>A[i];
        vector<string>B(n);
        for(int i=0;i<n;i++) cin>>B[i];
        int rptamax=0,rptamin=0;
        for(int i=0;i<n;i++){
            int a=0,b=0;
            for(auto x:A[i]){
                if(x=='#') a++;
            }
            for(auto x:B[i]){
                if(x=='#') b++;
            }
            int maxi=a*b;
            int mini=max(a,b);
            rptamax+=maxi;
            rptamin+=mini;
        }
        cout<<rptamax<<" "<<rptamin<<endl;
    }

}
