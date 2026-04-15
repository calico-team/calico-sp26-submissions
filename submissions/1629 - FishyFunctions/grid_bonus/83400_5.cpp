#include <iostream>

const int N = 1e5;
int a[N];

void test(){
	int n; std::cin >> n;

	for(int i=0; i<n; ++i) std::cin >> a[i];

	for(int i=1; i<n-1; ++i){
		if(a[i] > a[i-1] && a[i] > a[i+1]) a[i] = std::max(a[i-1], a[i+1]);
		if(a[i] < a[i-1] && a[i] < a[i+1]) a[i] = std::min(a[i-1], a[i+1]);
	}

	for(int i=0; i<n; ++i) std::cout << a[i] << " \n"[i==n-1];
}

int main(){
	int t; std::cin >> t;
	while(t--) test();
}
