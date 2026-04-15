/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        vector<int> v;
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        if(v.size()%2==1){
            for(int j=0; j<n; j++){
                cout<<v[v.size()/2]<<" ";
            }
        }
        else{
            for(int j=0; j<n; j++){
                cout<<(v[v.size()/2]+v[v.size()/2-1])/2<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}