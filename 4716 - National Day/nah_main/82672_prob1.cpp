#include<bits/stdc++.h>
using namespace std;

int t,n,p,r,k,e,cnt;

int main() {
    cin>>t;
    for (int a=1;a<=t;a++) {
        cnt = 0;
        cin>>n>>p>>r>>k;
        for (int i=1;i<=n;i++) {
            cin>>e;
            p -= e;
            cnt++;
            if (cnt%k==0) e += r;
            if (p<=0) {
                cout<<"nah i’d lose";
                return 0;
            }
        }
        cout<<"nah i’d win";
    }
}