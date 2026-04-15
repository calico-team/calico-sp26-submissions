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
        int a, b, c, d, e;
        cin>>a>>b>>c>>d>>e;
        vector<vector<int>> asteroids;
        for(int j=0; j<a; j++){
            vector<int> coord;
            int x, y;
            cin>>x>>y;
            coord.push_back(x);
            coord.push_back(y);
            asteroids.push_back(coord);
        }
        int curx=asteroids[0][0], cury=asteroids[0][1];
        bool flag=0;
        while(flag==0){
            curx+=e;
            cury+=d;
            for(int j=0; j<asteroids.size(); j++){
                if(curx%b==asteroids[j][0]&&cury%c==asteroids[j][1]&&flag==0){
                    cout<<j<<endl;
                    flag=1;
                }
            }
        }
    }
    return 0;
}