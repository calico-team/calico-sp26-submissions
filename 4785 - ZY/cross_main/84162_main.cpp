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
#include <iomanip>
using namespace std;

int main() {
    int fghj; cin>>fghj;
    for (int ji=0;ji<fghj;ji++){
        int a,b;
        cin>>a>>b;
        for (int i=0;i<a;i++){
            for (int j=0;j<b;j++){
                if (j > 0) cout<<' ';
                cout<<((2*i)+j)%5;
            }
            cout<<endl;
        }
    }
}
