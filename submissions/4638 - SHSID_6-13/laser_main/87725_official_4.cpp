#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int K, N, M, P, Q;
		cin >> K >> N >> M >> P >> Q;
		vector<int> X(K), Y(K);
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			X[i] = a;
			Y[i] = b;
		}
		for(int i=1, j; i<=1000; i++) {
			for(j=0; j<K; j++) {
				if((X[0]+i*Q)%N==X[j] && (Y[0]+i*P)%M==Y[j]) {
					cout<<j<<endl;
					break;
				}
			}
			if((X[0]+i*Q)%N==X[j] && (Y[0]+i*P)%M==Y[j]){
					break;
			}
		}
	}
	return 0;
}
