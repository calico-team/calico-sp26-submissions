#include <bits/stdc++.h>
using namespace std;
int main()
{
int T;
cin>>T;
while(T--){
    int L,W,E,R;
    cin>>L>>W>>E>>R;
    cout<<E/(2*(L+W)*R)<<endl;
}
    return 0;
}