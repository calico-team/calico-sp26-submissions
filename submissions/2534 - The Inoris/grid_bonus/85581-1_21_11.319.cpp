#include <bits/stdc++.h>
using namespace std;
void eachCase()
{
    int n;
    cin>>n;
    vector<int> C(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>C[i];
    }

    cout<<C[0]<<" ";

    for(int i=1;i<n-1;i++)
    {
        int A[3]={C[i-1],C[i],C[i+1]};

        sort(A,A+3);

        cout<<A[1]<<" ";
    }

    cout<<C[n-1];
    cout<<endl;
}


int main()
{
    int T;
    cin>>T;
    while(T--) eachCase();
}