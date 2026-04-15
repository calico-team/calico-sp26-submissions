#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long A[100005], L[100005], R[100005], B[100005];
long long change(long long x, long long left, long long right){
	if(x<left)return left;
	if(x>right) return right;
	return x;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		L[1]=A[1];
		R[1]=A[1];
		for(int i=2; i<=N; i++){
			long long a=A[i];
			if(a<L[i-1]){
				L[i]=a;
				R[i]=R[i-1];
			} else if(a>R[i-1]){
				L[i]=L[i-1];
				R[i]=a;
			} else{
				L[i]=a;
				R[i]=a;
			}
		}
		B[N]=L[N];
		for(int i=N-1; i>=1; i--){
			B[i]=change(B[i+1], L[i], R[i]);
		}
		for(int i=1; i<=N; i++){
			if(i>1) cout<<" ";
			cout<<B[i];
		}
		cout<<endl;
	}
	return 0;
}
