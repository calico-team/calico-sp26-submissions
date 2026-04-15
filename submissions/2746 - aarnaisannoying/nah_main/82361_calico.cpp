#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		int n, k;
		long long power, restore;
		cin >> n >> power >> restore >> k;

		vector<long long> curses(n);
		for (long long &curse : curses) {
			cin >> curse;
		}

		bool can_win = true;
		int defeats_since_last_use = 0;

		for (long long curse : curses) {
			if (power < curse) {
				if (defeats_since_last_use == k) {
					power += restore;
					defeats_since_last_use = 0;
				}
			}

			power -= curse;
			if (power < 0) {
				can_win = false;
				break;
			}

			++defeats_since_last_use;
			if (defeats_since_last_use > k) {
				defeats_since_last_use = k;
			}
		}

		cout << (can_win ? "nah i'd win" : "nah i'd lose") << '\n';
	}

	return 0;
}