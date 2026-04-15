#include <bits/stdc++.h>
using namespace std;
int s[110];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		string a,b;
		cin >> a >> b;
		int last = -1;
		int lena = a.size();
		int lenb = b.size();
		memset(s , 0 , sizeof(s));
		for(int i = 0 ; i < lenb ; i++){
			for(int j = last + 1 ; j < lena ; j++){
				if(b[i] == a[j]){
					s[j] = 1;
					last = j;
					break;
				}
			}
		}
		for(int i = 0 ; i < lena ; i++){
			if(s[i] == 1){
				cout << a[i];
			}
			else{
				cout << "#";
			}
		}
		cout << endl;
	}
	return 0;
} 
