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
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int l, w, e, r;
        cin>>l>>w>>e>>r;
        int perim = (l*2)+(w*2);
        double energyPerLap=perim*r;
        cout<<ceil(e/energyPerLap)<<endl;
    }
}
