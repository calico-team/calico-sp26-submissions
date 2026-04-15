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
        int n, p, r ,k;
        cin>>n>>p>>r>>k;
        int kCount = 0;
        bool f = false;
        for(int i = 0; i < n; i++){
            int e;
            cin>>e;//current

            p-=e;
            if(p < 0){
                f=true;
                continue;
            }
            kCount++;//defeated one more
            if(kCount >= k){
                kCount-=k;
                p+=r;
            }
            
        }
        cout<<(!f ? "nah i’d win" : "nah i’d lose")<<endl;

    }


    // cout<<<<endl;
}
