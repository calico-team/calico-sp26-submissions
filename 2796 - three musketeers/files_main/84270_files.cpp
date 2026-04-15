// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	string a,b;
    cin>>a>>b;
    int p = 0;
    for(int i=0;i<b.size();i++){
        while(true){
            if(a[p] == b[i]){
                break;
            }
            a[p] = '#';
        }
    }
    cout<<a<<endl;
}
