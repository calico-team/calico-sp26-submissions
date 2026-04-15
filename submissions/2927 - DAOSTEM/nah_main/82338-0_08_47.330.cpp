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
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b, c, d;
        int z=0;
        cin>>a>>b>>c>>d;
        bool flag=1;
        for(int j=0; j<a; j++){
            int curse;
            cin>>curse;
            b-=curse;
            z++;
            if(b<0) flag=0;
            if(z==d){
                z=0;
                b+=c;
            }
        }
        if(flag==0) cout<<"nah i'd lose"<<endl;
        else cout<<"nah i'd win"<<endl;
    }
    return 0;
}