#include <iostream>
#include <array>
#include <set>

const int N = 1e3;

int b[N][N], ts[N][N];
bool v[N][N];

void set(int x, int y, int z){
	b[(x+N)%N][(y+N)%N] = z;
}

void set2(int x, int y){
	v[(x+N)%N][(y+N)%N] = 1;
}

void set3(int x, int y, int z){
	ts[(x+N)%N][(y+N)%N] = z;
}

int get(int x, int y){
	return b[(x+N)%N][(y+N)%N];
}

int get3(int x, int y){
	return ts[(x+N)%N][(y+N)%N];
}

std::set<std::array<int, 4>> s;
int t;

void add(int x, int y, int z){
	if(get(x, y) != 0){
		if(!(z == 1 && get(x, y) == 2 && get3(x, y) == t)) return;
	}

	set(x, y, z);
	set3(x, y, t);
	if(z == 2) set2(x, y);

	int o = z == 1 ? 2 : 7;

	s.insert({t+o, x-1, y, z});
	s.insert({t+o, x+1, y, z});
	s.insert({t+o, x, y-1, z});
	s.insert({t+o, x, y+1, z});
}

void test(){
	for(int i=0; i<1e3; ++i)
		for(int j=0; j<1e3; ++j)
			b[i][j] = v[i][j] = 0;

	s.clear();
	t = 0;

	{
		int x, y; std::cin >> x >> y;
		add(x, y, 1);
	};

	{
		int x, y; std::cin >> x >> y;
		add(x, y, 2);
	};

	int last = 0;

	while(s.size() && t < last+10){
		auto e = *s.begin();

		t = e[0];
		add(e[1], e[2], e[3]);
		if(e[3] == 2) last = t;
		
		s.erase(e);
	}

	int count = 0;

	for(int i=0; i<1e3; ++i)
		for(int j=0; j<1e3; ++j)
			count += v[i][j];

	std::cout << count << '\n';
}

int main(){
	int t; std::cin >> t;
	while(t--) test();
}
