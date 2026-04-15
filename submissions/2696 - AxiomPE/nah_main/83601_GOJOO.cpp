#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	if (!(cin >> T)) return 0;

	while (T--){
		long long n, p, r, k;
		cin >> n >> p >> r >> k;

		vector<long long> e(n);
		bool gana = true;
		int derrot = 0;

		for (int i = 0; i < n; i ++){
			cin >> e[i];
		
			if (gana){
				p = p - e[i];


				if (p < 0){
				gana = false;
				} else {
					derrot++;
					if (derrot == k){
						p = p + r;
						derrot = 0;
					}
				}
			}
		}
					

		if (gana){
			cout << "nah i'd win" << "\n";
		} else {
			cout << "nah i'd lose" << "\n";
		}
	}
	return 0;
}