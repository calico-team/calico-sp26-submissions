#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back

int n;
int ar[3];

void sol(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> ar[i];

    int top=0;
    for(int i=0;i+1<n;i++) top+=abs(ar[i]-ar[i+1]);

    int tmp[3];

    int count=LLONG_MAX;

    if(n==1){cout << ar[0] << '\n'; return;}
    else if(n==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int res=0;
                res+=abs(ar[i]-ar[j]);
                res+=abs(ar[i]-ar[0]) + abs(ar[j]-ar[1]);

                if(res+top<count){
                    tmp[0]=ar[i];
                    tmp[1]=ar[j];
                    count=res+top;
                }
            }
        }
    }
    else if(n==3){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    int res=0;
                    res+=abs(ar[i]-ar[j]) + abs(ar[j]-ar[k]);
                    res+=abs(ar[i]-ar[0]) + abs(ar[j]-ar[1]) + abs(ar[k]-ar[2]);
                    
                    if(res+top<count){
                        tmp[0]=ar[i];
                        tmp[1]=ar[j];
                        tmp[2]=ar[k];
                        count=res+top;
                    }
                }
            }
        }
    }

    for(int i=0;i<n;i++) cout << tmp[i] << ' ';
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc=1;
    cin >> tc;
    while(tc--) sol();
}