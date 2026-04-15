#include "bits/stdc++.h"

using namespace std;

char a[102], b[102];

void solve(){
	scanf("%s%s", a, b);
	printf("%s\n%s\n", a, b);
	int n = strlen(a), m = strlen(b);
	int l = 0;
	for(int i=0; i<m; i++){
		while(l < n && a[l] != b[i]){
			a[l] = '#';
			l++;
		}
		l++;
	}
	while(l < n) a[l++] = '#';
	printf("%s\n", a);
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}
