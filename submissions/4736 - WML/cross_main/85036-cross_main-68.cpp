#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val=(i+2*j)%5;
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
