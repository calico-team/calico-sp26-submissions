#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--)
    {
        cin >> n;
        vector<int> vec(n + 2, 0);
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> vec[i];
        }
        for (int i = 1 ; i <= n ; i++)
        {
            vector<int> ss = {vec[i-1], vec[i], vec[i+1]};
            sort(ss.begin(), ss.end());
            cout << ss[1] << " ";
        }
        cout << "\n";

    }
    return 0;
}
