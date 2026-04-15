#include <bits/stdc++.h>
using namespace std;

#define ll long long

int grid[405][405];
int leftmost_1, rightmost_1, topmost_1, bottommost_1;
int leftmost_2, rightmost_2, topmost_2, bottommost_2;

int &get(int x, int y) {
	x += 200; y += 200;
	if (x < 0 || x > 400 || y < 0 || y > 400) {
		static int dummy = 0;
		return dummy;
	}
	return grid[x][y];
}

vector<tuple<int, int, int>> to_set;

void set_val(int x, int y, int val) {
	int &cell = get(x, y);
	if (cell == 0) {
		to_set.emplace_back(x, y, val);
	}
}

void commit(int &area_1, int &area_2) {
	for (auto &[x, y, val] : to_set) {
		if (val == 1) {
			get(x, y) = val;
			area_1++;
			leftmost_1 = min(leftmost_1, x);
			rightmost_1 = max(rightmost_1, x);
			topmost_1 = max(topmost_1, y);
			bottommost_1 = min(bottommost_1, y);
		} else if (get(x, y) == 0) {
			get(x, y) = val;
			area_2++;
			leftmost_2 = min(leftmost_2, x);
			rightmost_2 = max(rightmost_2, x);
			topmost_2 = max(topmost_2, y);
			bottommost_2 = min(bottommost_2, y);
		}
		// cout << "Set (" << x << ", " << y << ") to " << val << '\n';
	}
	to_set.clear();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		memset(grid, 0, sizeof(grid));
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		get(x, y) = 1;
		get(a, b) = 2;
		int prev_1_area = 1, prev_2_area = 1;
		int area_1 = 1, area_2 = 1;
		leftmost_1 = x, rightmost_1 = x, topmost_1 = y, bottommost_1 = y;
		leftmost_2 = a, rightmost_2 = a, topmost_2 = b, bottommost_2 = b;
		for (int i = 1; i < 1000; i++) {
			if (i % 2 && i % 7) continue;
			if (i % 2 == 0) {
				// spread 1
				for (int x = leftmost_1; x <= rightmost_1; x++) {
					for (int y = bottommost_1; y <= topmost_1; y++) {
						if (get(x, y) == 1) {
							set_val(x+1, y, 1);
							set_val(x-1, y, 1);
							set_val(x, y+1, 1);
							set_val(x, y-1, 1);
						}
					}
				}
			}
			if (i % 7 == 0) {
				for (int x = leftmost_2; x <= rightmost_2; x++) {
					for (int y = bottommost_2; y <= topmost_2; y++) {
						if (get(x, y) == 2) {
							set_val(x+1, y, 2);
							set_val(x-1, y, 2);
							set_val(x, y+1, 2);
							set_val(x, y-1, 2);
						}
					}
				}
			}
			commit(area_1, area_2);

			if (prev_2_area == area_2 && i % 7 == 0) {
				break;
			}
			prev_1_area = area_1;
			prev_2_area = area_2;
		}
		cout << area_2 << '\n';
	}
}