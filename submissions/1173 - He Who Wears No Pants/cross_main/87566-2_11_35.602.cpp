#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int arr[1000][1000];

int main() {
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);

        int c = 0;
        for (int i = 0; i < n; i++) {
            int c2 = 0;
            c2 = (c2 + c) % 5;
            for (int j = 0; j < m; j++) {
                arr[i][j] = c2;
                c2 = (c2 + 1) % 5;
            } c += 2;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) printf("%d ", arr[i][j]);
            printf("\n");
        }
    }
}