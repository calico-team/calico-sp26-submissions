# include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tc;
    cin >> tc;
    for(int tc_ = 0; tc_ < tc; tc_++){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int x = 0; x < n; x++){
            cin >> nums[x];
        }
        for(int x = 1; x < n - 1; x++){
            if((nums[x] > nums[x + 1] && nums[x] > nums[x - 1])){
                nums[x] = max(nums[x + 1], nums[x - 1]);
            }
            else if(nums[x] < nums[x + 1] && nums[x] < nums[x - 1]){
                nums[x] = min(nums[x + 1], nums[x - 1]);
            }
        }
        for(int x = 0; x < n; x++){
            cout << nums[x] << endl;
        }
    }
}