#include <bits/stdc++.h>

void solve() {
	int k,n,m,p,q;
	std::cin >> k >> n >> m >> p >> q;
	/*
	0 <= x <= n-1
	0 <= y <= m-1

	x(i+1) = (x(i) + q) % n;
	y(i+1) = (y(i) + p) % m;

	p and q are coprime (gcd(p,q)  = 1)

	*/
	int arr[n][m];
	//arr[x][y]
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			arr[i][j] = 0;
		}
	}

	// k asteroids
	int sx,sy,x,y;
	for(int i = 0; i < k; i++) {
		std::cin >> x >> y;
		if(i == 0) {
			sx = x;
			sy = y;
		}
		arr[x][y] = i+1;
	}
	x = sx;y = sy;
	while(true) {
		x = (x+q)%n;
		y = (y+p)%m;

		if(arr[x][y] != 0) {
			std::cout << arr[x][y]-1 << std::endl;
			break;
		}
	}
}

int main() {
	//partial 

	int t;std::cin >> t;
	while(t--) {
		solve();
	}
}