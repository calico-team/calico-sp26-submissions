#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>x(n,0),y(n,0);
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            for(int j=0;j<s.length();j++){
                if(s[j]=='#'){
                    x[i]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            for(int j=0;j<s.length();j++){
                if(s[j]=='#'){
                    y[i]++;
                }
            }
        }
        int ansMax=0,ansMin=0;
        for(int i=0;i<n;i++){
            ansMax+=x[i]*y[i];
            ansMin+=max(x[i],y[i]);
        }
        cout << ansMax << " " << ansMin << endl;
    }
}