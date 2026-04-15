#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[100005];
int l[100005], r[100005];
int b[100005];

void solve(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	l[1] = r[1] = a[1];
	for(int i=2; i<=n; i++){
		if(a[i] < l[i-1]){
			l[i] = a[i];
			r[i] = l[i-1];
		}
		else if(a[i] > r[i-1]){
			l[i] = r[i-1];
			r[i] = a[i];
		}
		else{
			l[i] = r[i] = a[i];
		}
	}
	b[n] = l[n];
	for(int i=n-1; i>=1; i--){
		if(b[i+1] < l[i]){
			b[i] = l[i];
		}
		else if(b[i+1] > r[i]){
			b[i] = r[i];
		}
		else{
			b[i] = b[i+1];
		}
	}
	for(int i=1; i<=n; i++){
		printf("%d ", b[i]);
	}
	printf("\n");
}

int main(){
	int t = 1;
	scanf("%d", &t);
	while(t--) solve();
}