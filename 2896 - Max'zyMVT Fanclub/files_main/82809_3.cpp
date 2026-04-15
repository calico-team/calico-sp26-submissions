#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--)
    {
        string graft, novemnotes;
        cin >> graft >> novemnotes;
        int pt = 0;
        for (char &ch : graft)
        {
            if (pt < novemnotes.size() and ch == novemnotes[pt])
            {
                pt++;
            }
            else
            {
                ch = '#';
            }
        }
        cout << graft << "\n";
    }
    return 0;
}