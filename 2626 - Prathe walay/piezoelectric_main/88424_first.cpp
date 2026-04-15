#include<bits/stdc++.h>
using namespace std;

int solve(int L, int W, int E, int R){
    int triangle_area = 2*(L+W);
    int per_lap = triangle_area * R;
    return E / per_lap;
}

void read_your_input(){
    int T;
    cin>>T;
    while(T--){
        int L,W,E,R;
        cin>>L>>W>>E>>R;
        cout<<solve(L,W,E,R)<<"\n";
    }
}

int main(){
    read_your_input();
    return 0;
}
