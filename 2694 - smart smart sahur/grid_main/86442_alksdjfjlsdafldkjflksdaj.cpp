#include <bits/stdc++.h>
#define DEBUG false
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;

signed main() {
    if(!DEBUG){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    else{
        (void)freopen("test.in", "r", stdin);
        (void)freopen("test.out", "w", stdout); 
    }
    int t;
    cin>>t;
    while(t--){
        int n, highest = -1, cnt = 0, cnt1 = 0, ans = 0;
        cin>>n;
        vector<int> arr(n);
        map<int, int> freq;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            freq[arr[i]]++;
            if(freq[arr[i]] == highest){
                cnt++;
                cnt1 += arr[i];
            }
            if(freq[arr[i]] > highest){
                highest = freq[arr[i]];
                cnt = 1;
                cnt1 = arr[i];
            }
        }
        int laverage = floor((double)cnt1 / cnt);
        int raverage = ceil((double)cnt1 / cnt);
        for(int i = 0; i < n; i++){
            if(arr[i] < raverage){
                cout<<laverage<<' ';
            }
            else{
                cout<<raverage<<' ';
            }
        }
        cout<<endl;
    }
}