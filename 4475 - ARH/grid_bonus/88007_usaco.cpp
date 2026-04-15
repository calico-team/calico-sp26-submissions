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
        int left_arr[100010];
        int right_arr[100010];
        int c, left = arr[0], right=arr[0];
        for(int i = 0;i<n;i++){
            int a = arr[i], new_left, new_right;
            if(a<=left){
                c+=left-a,new_left=a,new_right=left;
            }else if(a>=right){
                c+=a-right,new_left=right,new_right=a;
            }else{
                new_left=a,new_right=a;
            }
            left=new_left,right=new_right;
            left_arr[i]=left;
            right_arr[i]=right;
        }
        int b[100010];
        b[n-1]=left_arr[n-1];
        for(int i = n-2;i>=0;i--){
            b[i]=max(left_arr[i],min(right_arr[i],b[i+1]));
        }
        for(int i = 0;i<n;i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
}