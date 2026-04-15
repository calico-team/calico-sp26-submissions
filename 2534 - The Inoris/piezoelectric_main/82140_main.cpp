#include <bits/stdc++.h>
using namespace std;
int single()
{
    int l,w,e,r;
    cin>>l>>w>>e>>r;

    int p=(l+w)*2;
    int each_loop=p*r;


    int ans=e/each_loop;
    return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--) cout<<single()<<endl;    
}