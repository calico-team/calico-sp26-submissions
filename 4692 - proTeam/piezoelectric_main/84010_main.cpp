#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        int L,W,E,R;
        cin>>L>>W>>E>>R;

        cout<< E/((2*(L+W))*R);
    }
    return 0;
}
