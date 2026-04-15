#include "bits/stdc++.h"

using namespace std;

void solve(){
	int l, w, e, r;
	scanf("%d%d%d%d", &l, &w, &e, &r);
	printf("%d\n", e / (2 * (l + w) * r));
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}
