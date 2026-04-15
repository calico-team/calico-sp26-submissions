#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){
	while(b!=0){
		long long t=a%b;
		a=b;
		b=t;
	}
	return a;
}
long long lcm(long long a, long long b){
	return a*b/gcd(a, b);
}
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
		int repeatX=N/gcd(N, Q);
		int repeatY=M/gcd(M, P);
		long long cycle=lcm(repeatX, repeatY);
		int answer=-1;
		for(long long i=1; i<=cycle; i++) {
			for(int j=0; j<K; j++) {
				if((X[0]+i*Q)%N==X[j] && (Y[0]+i*P)%M==Y[j]) {
					answer=j;
					break;
				}
			}
			if(answer!=-1) break;
		}
		cout<<answer<<endl;
	}
	return 0;
}
