#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin>>T;
    while(T--){
        long long P; int A,B;
        cin>>P>>A>>B;
        if(!A&&!B){ cout<<"1 1\n>\n"; continue; }

        long long p3=1;
        for(int i=0;i<B;i++){ p3*=3; if(p3>1000000000000LL) break; }

        long long X,Y;
        if(p3>P) X=0,Y=P;
        else X=P/p3,Y=P%p3;

        vector<int> b(A),n(B);
        for(int k=0;k<A;k++) b[k]=(X>>(A-1-k))&1;
        long long tmp=Y;
        for(int j=B-1;j>=0;j--){ n[j]=tmp%3; tmp/=3; }

        int tot=A+B, cols=2*tot+2;
        vector<string> g(3,string(cols,'.'));
        g[0][0]='v'; g[1][0]='>';
        for(int s=0;s<tot;s++){
            int c=2*s+1;
            g[1][c]='S'; g[1][c+1]='>';
            if(s<A){
                g[2][c]=b[s]?'v':'x';
            } else {
                int nj=n[s-A];
                g[0][c]=nj?'^':'x';
                g[2][c]=(nj==2)?'v':'x';
            }
        }
        g[1][2*tot+1]='x';
        cout<<3<<" "<<cols<<"\n";
        for(auto&r:g) cout<<r<<"\n";
    }
}
