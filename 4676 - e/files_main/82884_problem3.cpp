#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    for(int k=0; k<n; k++)
    {
        string a;
        string b;
        
        cin>>a>>b;
        int counter=0;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i]!=b[counter]) a[i] = '#';
            if(a[i]==b[counter]) counter++;
        }
        cout<<a<<endl;
    }
    
}