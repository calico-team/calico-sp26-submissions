#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        vector<string> S1(N), S2(N);
        for(int i=0; i<N; i++) cin>>S1[i];
        for(int i=0; i<N; i++) cin>>S2[i]; 
        long long mx=0, mn=0;
        for(int i=0; i<N; i++) {
            int a=0, b=0;
            for(char c:S1[i]) if(c=='#') a++;
            for(char c:S2[i]) if(c=='#') b++;
            mx+=1LL*a*b;
            mn+=max(a, b);
        }
        cout<<mx<<' '<<mn<<'\n';
    }
    return 0;
}