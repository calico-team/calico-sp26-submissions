/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> updateMycelium(vector<vector<char>> v){
    vector<char> help(40, '0');
    vector<vector<char>> temp(40, help);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            temp[i][j]=v[i][j];
        }
    }
    int count=0, countt=0;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            if(v[i][j]=='m'){
                count++;
                int x=i+1, y=j;
                if(x>=0&&y>=0){
                    if(v[x][y]!='g') temp[x][y]='m';
                }
                x=i-1, y=j;
                if(x>=0&&y>=0){
                    if(v[x][y]!='g') temp[x][y]='m';
                }
                x=i, y=j-1;
                if(x>=0&&y>=0){
                    if(v[x][y]!='g') temp[x][y]='m';
                }
                x=i, y=j+1;
                if(x>=0&&y>=0){
                    if(v[x][y]!='g') temp[x][y]='m';
                }
            }
        }
    }
    for(int i=0; i<temp.size(); i++){
        for(int j=0; j<temp[i].size(); j++){
            if(temp[i][j]=='m') countt++;
        }
    }
    if(count==countt){
        temp[0][0]='x';
    }
    return temp;
}
vector<vector<char>> updateGrass(vector<vector<char>> v){
    vector<char> help(40, '0');
    vector<vector<char>> temp(40, help);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            temp[i][j]=v[i][j];
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            if(v[i][j]=='g'){
                int x=i+1, y=j;
                if(x>=0&&y>=0){
                    if(v[x][y]!='m') temp[x][y]='g';
                }
                x=i-1, y=j;
                if(x>=0&&y>=0){
                    if(v[x][y]!='m') temp[x][y]='g';
                }
                x=i, y=j-1;
                if(x>=0&&y>=0){
                    if(v[x][y]!='m') temp[x][y]='g';
                }
                x=i, y=j+1;
                if(x>=0&&y>=0){
                    if(v[x][y]!='m') temp[x][y]='g';
                }
            }
        }
    }
    return temp;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int gx, gy, mx, my;
        cin>>gy>>gx>>my>>mx;
        mx=20+abs(mx-gx);
        my=20+abs(my-gy);
        gx=20, gy=20;
        vector<char> help(40, '0');
        vector<vector<char>> v(40, help);
        v[20][20]='g';
        v[mx][my]='m';
        int t=1;
        bool flag=0;
        while(flag==0){
            t++;
            if(t%7==0){
                vector<vector<char>> ll;
                ll=updateMycelium(v);
                if(ll[0][0]=='x'){
                    flag=1;
                }
                else v=ll;
            }
            if(t%2==0){
                v=updateGrass(v);
            }
        }
        int ans=0;
        for(int j=0; j<v.size(); j++){
            for(int k=0; k<v.size(); k++){
                if(v[j][k]=='m') ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}