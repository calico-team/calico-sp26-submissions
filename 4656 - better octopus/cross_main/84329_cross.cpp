#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        int list[5]= {0,2,4,1,3};
        scanf("%d%d",&a,&b);
        for (int i = 0; i < a; i++) {
            int counter = list[i%5];
            for (int j = 0; j < b; j++) {
                printf("%d ", (counter+j)%5);
            }
            printf("\n");
        }
    }
}
