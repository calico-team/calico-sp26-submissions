#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
	cin >> t;
    while (t--) {
        char a[110],b[110],ans[110];
        for(int i=0;i<110;i++){
        	ans[i]='#';
		}
        cin>>a;
		cin>>b;
        for(int i=0;i<strlen(b);i++){
        	for(int j=0;j<strlen(a);j++){
        		if(a[j]==b[i]){
        			ans[j]=b[i];
        			a[j]='*';
        			break;
				}else{
					a[j]='*';
				}
			} 
		}
        for(int i=0;i<strlen(a);i++){
        	cout<<ans[i];
		}
		cout<<endl;
    }
}
