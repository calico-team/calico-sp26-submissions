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
        int p,a,b;
        cin>>p>>a>>b;
        int rows = 3 + 2*a + 2*b;
        int cols = 5;
        vector<string> grid(rows, string(cols, '.'));
        grid[0] = ">>v..";
        grid[1] = "..v..";
        int r = 2;
        int pow = 1;
        for (int i = 0; i < b; i++){
            pow*=3;
        }
        int twosplit = p/pow;
        int threesplit = p%pow;
        vi twobits(a), threebits(b);
        int temp = twosplit;
        for (int i = 0; i < a; i++){
            twobits[a-i-1] = temp%2;
            temp/=2;
        }
        temp = threesplit;
        for (int i = 0; i < b; i++){
            threebits[b-i-1] = temp%3;
            temp/=3;
        }

        for (int bit : twobits){
            if (bit == 0){
                grid[r++] = ".XS..";
                grid[r++] = "..v..";
            }
            else{
                grid[r++] = "<<S..";
                grid[r++] = "..v..";
            }
        }

        for (int bit : threebits){
            if (bit == 2){
                grid[r++] = "<<S>>";
                grid[r++] = "..v..";
            }
            else if (bit == 1){
                grid[r++] = ".XS>>";
                grid[r++] = "..v..";
            }
            else{
                grid[r++] = ".XSX.";
                grid[r++] = "..v..";
            }
        }
        grid[r] = "..X..";
        cout<<rows<<" "<<cols<<endl;
        for (string s : grid){
            cout<<s<<endl;
        }
    }
}
