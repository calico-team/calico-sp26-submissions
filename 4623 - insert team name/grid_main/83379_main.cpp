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
        vector<int> nums(n), a(n), b(n);
        for(int x = 0; x < n; x++){
            cin >> nums[x];
        }
        a[0] = nums[0];
        for(int x = 1; x < n; x++){
            a[x] = min(a[x - 1], nums[x]);
        }
        b[n - 1] = nums[n - 1];
        for(int x = n - 2; x >= 0; --x){
            b[x] = min(b[x + 1], nums[x]);
        }
        for(int x = 0; x < n; x++){
            cout << max(a[x], b[x]) << ' ';
        }
        cout << endl;
    }
}