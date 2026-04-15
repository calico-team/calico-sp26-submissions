#include <iostream>
using namespace std;
int main(){
int x;
cin >>x;
int a, b, c, d;
for (int i=0; i<x; i++){
cin >> a >> b >> c >> d;
a+=b;
c/=d;
c/=a;
cout << c << endl;
}

}