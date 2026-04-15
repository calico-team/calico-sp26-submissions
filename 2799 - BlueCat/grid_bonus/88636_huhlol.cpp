#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<long long>a(n);
        for(int i=0;i<n;i++)cin>>a[i];

        if(n==1){
            cout<<a[0]<<"\n";
            continue;
        }

        vector<long long>lo(n),hi(n);

        long long l=a[0],r=a[0];
        lo[0]=l;
        hi[0]=r;

        for(int i=1;i<n;i++){
            long long nl=min(a[i],r);
            long long nr=max(a[i],l);
            l=nl;
            r=nr;
            lo[i]=l;
            hi[i]=r;


        }

        vector<long long>b(n);



        b[n-1]=max(lo[n-1],min(hi[n-1],a[n-1]));


        for(int i=n-2;i>=0;i--){
            b[i]=max(lo[i],min(hi[i],b[i+1]));


        }

        for(int i=0;i<n;i++){
            cout<<b[i];
            if(i+1<n)cout<<" ";


        }
        cout<<endl;
    }

    return 0;
}