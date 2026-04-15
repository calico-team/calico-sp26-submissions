#include <bits/stdc++.h>
using namespace std;
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

int main(){
    setIO("");
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << (j + i*2) % 5 << (j == m-1 ? "" : " ");
            }
            cout<<endl;
        }
    }
}
