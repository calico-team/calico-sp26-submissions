#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define endl "\n"
#define mp make_pair
void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin); 
		freopen((name+".out").c_str(), "w", stdout);
	}
}

signed main(){
    setIO("");
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vi arr(n);
        for (int i = 0; i < n; i++) cin>>arr[i];
        vi l(n), r(n);
        l[0] = arr[0];
        r[0] = arr[0];
        for (int i = 1; i < n; i++){
            if (arr[i] > r[i-1]){
                l[i] = r[i-1];
                r[i] = arr[i];
            }
            else if (arr[i] < l[i-1]){
                l[i] = arr[i];
                r[i] = l[i-1];
            }
            else {
                l[i] = arr[i];
                r[i] = arr[i];
            }
        }


        vi b(n);
        b[n-1] = r[n-1];
        for (int i = n-1; i>=1; i--){
            int mini = -1e9-1, maxi = 1e9+1;
            if (i>=2){
                mini = min(arr[i-1], l[i-2]);
                maxi = max(arr[i-1], r[i-2]);
            }

            if (b[i] >= mini && b[i] <= maxi){
                b[i-1] = b[i];
            }
            else if (b[i] < mini){
                b[i-1] = mini;
            }
            else {
                b[i-1] = maxi;
            }
        }
        for (int i = 0; i < n; i++) cout<<b[i]<<(i == n-1 ? "" : " ");
        cout<<endl;
    }
}
