//6 5 60 5 1 12 6 23 8 10 4 42 10 3 40 10 5 8 3 10 5 2 5 5 5 3 20 50 3 10 10 10 4 5 10 1 4 10 10 10 1 10 100 1 15

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, p, r, k, e, c; bool b;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d %d %d", &n, &p, &r, &k);
        c = 0;
        b = true;

        for (int i = 0; i < n; i++) {
            scanf("%d", &e);
            if (b) {
                p -= e;

                if (p < 0) {
                    while (c >= k) {
                        c -= k;
                        p += r;
                    }
                    if (p < 0) {
                        b = false;
                    }
                }

                c++;
            }
        }

        if (b) {
            printf("nah i'd win\n");
        } else {
            printf("nah i'd lose\n");
        }
    }
}