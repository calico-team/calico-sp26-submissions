#include "bits/stdc++.h"

using namespace std;

void solve(){
	int n, p, r, k; 
	scanf("%d%d%d%d", &n, &p, &r, &k);
	vector<int> e(n);
	bool lose = false;
	for(int i=0; i<n; i++){
		scanf("%d", &e[i]);
		p -= e[i];
		if(p < 0){
			lose = true;
		}
		if((i+1)%k == 0){
			p += r;
		}
	}
	printf("nah i'd %s\n", lose ? "lose" : "win");
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}
