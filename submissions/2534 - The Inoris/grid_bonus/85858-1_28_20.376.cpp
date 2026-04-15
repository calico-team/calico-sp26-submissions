#include <bits/stdc++.h>
using namespace std;
void eachCase()
{
    int n;
    cin>>n;
    vector<int> C(n+1);
    vector<int> P(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>C[i];
    }

    cout<<C[0]<<" ";
    P[0]=1;

    for(int i=1;i<n-1;i++)
    {
        int A[3]={P[i-1],C[i],C[i+1]};

        sort(A,A+3);

        P[i]=A[1];
        cout<<P[i]<<" ";
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