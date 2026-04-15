#include <iostream>

const int N = 1e3;
int a[N];

void test(){
	int n; std::cin >> n;

	for(int i=0; i<n; ++i){
		a[i] = 0;
		for(int j=0; j<n; ++j){
			char c; std::cin >> c;
			a[i] += c == '#';
		}
	}

	int min = 0, max = 0;

	for(int i=0; i<n; ++i){
		int b = 0;
		for(int j=0; j<n; ++j){
			char c; std::cin >> c;
			b += c == '#';
		}

		min += std::max(b, a[i]);
		max += b * a[i];
	}

	std::cout << max << ' ' << min << '\n';
}

int main(){
	int t; std::cin >> t;
	while(t--) test();
}
