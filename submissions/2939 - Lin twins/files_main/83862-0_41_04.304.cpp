#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include<map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;//woah
//    vector<vector<int>> a(3, vector<int>(3));



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("temporary.in");//temporary
    ofstream fout("temporary.out"); 
    
    int t;
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        // cout<<a<<' '<<b<<endl;
        int bCounter = 0;
        for(int i = 0; i < a.size(); i++){
            if(b[bCounter] == a[i]){
                bCounter++;
            }else{
                a[i] = '#';
            }
        }
        // cout<<2;
            cout<<a<<endl;

    }

}
