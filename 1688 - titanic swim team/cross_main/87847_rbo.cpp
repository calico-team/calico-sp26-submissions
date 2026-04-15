#include <iostream>
#include <vector>
using namespace std;
int main(){
 int x;
 cin >> x;
 for (int i=0; i<x; i++){
    int a, b;
    cin >> a >> b;
    vector <vector<int>> v (a, vector<int>(b));
    for(int i=0; i<b; i++){
        v[0][i]=i%5;
        cout << i%5 << " ";
    }
    cout << endl;
    for (int i=1; i<a; i++){
        for (int j=0; j<b; j++){
            int m = v[i-1][j] + 2;
            m%=5;
            cout << m << " "; 
            v[i][j]=m;
        }
        cout << endl;
    }
  }   
}