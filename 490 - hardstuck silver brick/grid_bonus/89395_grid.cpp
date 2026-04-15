#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        int res=INT_MAX,a=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++)count+=abs(arr[i]-arr[j]);
            if(count<res){
                res=count;
                a=i;
            }
        }
        int count=0;
        for(int i=1;i<n;i++)count+=abs(arr[i]-arr[i-1]);
        if(count<res)a=-1;
        if(a!=-1){
            for(int i=0;i<n;i++)cout<<arr[a]<<" ";
            continue;
        }
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl;
    }
}
