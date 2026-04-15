#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;

    while (T--)
    {
        int l, w, e, r;
        cin>>l>>w>>e>>r;
        cout<<e/((l+w)*2*r)<<endl;
    }

    return 0;
}