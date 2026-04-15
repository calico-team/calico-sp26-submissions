#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[100010];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        for(int i = 0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}