#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;

void solve(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d ", (i+2*j)%5);
		}
		printf("\n");
	}
}

int main(){
	int t = 1;
	scanf("%d", &t);
	while(t--) solve();
}