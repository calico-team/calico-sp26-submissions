#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int a[N], b[N];
int mid(int x, int y, int z){
    int c[3]={x,y,z};
    sort(c,c+3);
    return c[1];
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    for(int t=1; t<=T; ++t){
        // cerr << "Case "<<t <<":\n";
        int n;
        cin >> n;
        for(int i=1; i<=n; ++i){
            cin >> a[i];
        }
        b[1]=a[1]; b[n]=a[n];
        for(int i=2; i<n; ++i){
            b[i]=mid(b[i-1], a[i], a[i+1]);
        }
        // for(int i=2; i<n; ++i){
        //     if(b[i]!=mid(b[i-1],b[i+1],a[i])){
        //         cerr << "ERR " << i << '\n';
        //     }
        //     // assert(b[i]==mid(b[i-1],b[i+1],a[i]));
        // }
        for(int i=1; i<=n; ++i){
            cout << b[i] << " \n"[i==n];
        }
    }
    return 0;
}