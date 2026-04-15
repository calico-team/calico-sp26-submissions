#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--){
        string A,B;
        cin>>A>>B;
        string ans=A;
        int j=0;
        for(int i=0;i<A.size();i++){
            if(j<B.size()&&A[i]==B[j]){
                j++;
            }else{
                ans[i]='#';
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

