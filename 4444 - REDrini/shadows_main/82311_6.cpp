#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
char s1[1003][1003], s2[1003][1003];

void solve(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf(" %s", s1[i]);
	}
	for(int i=0; i<n; i++){
		scanf(" %s", s2[i]);
	}
	int mx = 0, mn = 0;
	for(int i=0; i<n; i++){
		int a = 0, b = 0;
		for(int j=0; j<n; j++){
			a += s1[i][j] == '#';
			b += s2[i][j] == '#';
		}
		mx += a*b;
		mn += max(a, b);
	}
	printf("%d %d\n", mx, mn);
}

int main(){
	int t = 1;
	scanf("%d", &t);
	while(t--) solve();
}