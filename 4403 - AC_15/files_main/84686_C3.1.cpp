#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--) {
        string A,B;
        cin>>A>>B;
        string res;
        int j=0;
        for(int i=0;i<A.size();i++) {
            char c=A[i];
            if (j<B.size()&&c==B[j]) {
                res+=c;
                j++;
            }else{
                res+='#';
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
