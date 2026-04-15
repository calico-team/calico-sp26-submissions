#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a, tar;
        int idx=0;
        cin>>a>>tar;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i]!=tar[idx])a[i]='#';
            else idx++;
        }
        cout<<a<<endl;
    }
}