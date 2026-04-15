#include <iostream>
#include <vector>

using namespace std;

void solve() {
int n, m;
cin >> n >> m;
vector<vector<int>> grid(n, vector<int>(m));
for(int a = 0; a < n; a++) {
for(int b = 0; b < m; b++) {
grid[a][b] = (a + 2 * b) % 5;
}
}
for(int a = 0; a < n; a++) {
for(int b = 0; b < m; b++) {
cout << grid[a][b] << " ";
}
cout << "\n";
}
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int test_cases;
cin >> test_cases;
for(int count = 0; count < test_cases; count++) {
solve();
}
return 0;
}