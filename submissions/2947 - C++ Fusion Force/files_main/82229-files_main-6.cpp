//written by sarah
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //problem 3 - the big ben files
    int t;
    string a, b;

    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> a >> b;
        int p=0;
        for (int i=0; i<a.size(); i++) {
            if (a[i]==b[p]) p++;
            else a[i]='#';
        }
        cout << a;
        if (i!=t-1) cout << endl;
    }
}