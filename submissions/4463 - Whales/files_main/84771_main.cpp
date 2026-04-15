#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;

    while (T--)
    {
        string a, b;
        cin>>a>>b;
        for (int i=0, j=0; i<a.size(); i++)
        {
            if (a[i]==b[j]) cout<<a[i], j++;
            else cout<<'#';
        }
        cout<<endl;
    }

    return 0;
}