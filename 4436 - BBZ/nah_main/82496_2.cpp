#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,p,r,k;
        cin >> n >> p >> r >> k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        bool check=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(p-arr[i]<0){
                if(cnt>=k){
                    p=r;
                    cnt=1;
                }
                else{
                    check=1;
                }
            }
            else{
                cnt++;
                p-=arr[i];
            }
        }
        if(check) cout << "nah i'd lose" << endl;
        else cout << "nah i'd win" << endl;
    }
}