#include "bits/extc++.h"

using namespace std;

void solve(){
    int n;
    cin>>n;
    string as[n],bs[n];
    int arr[n],brr[n];
    for(int i = 0; i<n; i++){
        cin>>as[i];
        int cnt=0;
        for(auto u: as[i]){
            cnt+=(u=='#');
        }
        arr[i]=cnt;
    }
    for(int i = 0; i<n; i++){
        cin>>bs[i];
        int cnt=0;
        for(auto u: bs[i]){
            cnt+=(u=='#');
        }
        brr[i]=cnt;
    }
    int tot1=0,tot2=0;
    for(int i = 0; i<n; i++){
        tot1+=brr[i]*arr[i];
        tot2+=max(arr[i],brr[i]);
    }
    cout<<tot1<<" "<<tot2<<"\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}
