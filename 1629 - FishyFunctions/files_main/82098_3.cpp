#include <iostream>
#include <string>

int main(){
	std::string a, b; std::cin >> a >> b;
	b += '~';

	int i = 0;

	for(int j=0; j<a.size(); ++j){
		if(a[j] != b[i]) a[j] = '#';
		else ++i;
	}

	std::cout << a << '\n';
}
