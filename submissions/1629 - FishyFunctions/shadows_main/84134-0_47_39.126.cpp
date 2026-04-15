#include <iostream>
#include <string>

const int N = 1e3;
int a[N];

void test(){
	int n; std::cin >> n;

	for(int i=0; i<n; ++i){
		a[i] = 0;
		std::string s; std::cin >> s;
		for(char c : s) a[i] += c == '#';
	}

	int min = 0, max = 0;

	for(int i=0; i<n; ++i){
		int b = 0;
		std::string s; std::cin >> s;
		for(char c : s) b += c == '#';

		min += std::max(b, a[i]);
		max += b * a[i];
	}

	std::cout << max << ' ' << min << '\n';
}

int main(){
	int t; std::cin >> t;
	while(t--) test();
}
