//
//  main.cpp
//  测试II
//
//  Created by Kevin on 2024/12/8.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

long long max(long long a, long long b){
    if (a < b) return b;
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int asd;
    cin>>asd;
    for (int ji=0;ji<asd;ji++){
        int a;
        cin>>a;
        char s1[1000][1001];
        for (int i=0;i<a;i++) cin>>s1[i];
        char s2[1000][1001];
        for (int i=0;i<a;i++) cin>>s2[i];
        long long maxV=0,minV=0;
        for (int z=0;z<a;z++) {
            int cntY=0;
            for (int y=0;y<a;y++){if (s1[z][y] == '#') cntY++;}
            int cntX=0;
            for (int x=0;x<a;x++){if (s2[z][x] == '#') cntX++;}
            maxV=maxV+(long long)cntX*(long long)cntY;
            minV=minV+max(cntX,cntY);
        }
        cout<<maxV<<" "<< minV<<endl;
    }
    return 0;
}
