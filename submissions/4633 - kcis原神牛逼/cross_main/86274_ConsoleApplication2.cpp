#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;



int main()
{
    int t, n, m, c, d;
    cin >> t;

    while (t > 0) {
        c = 0;
        cin >> n >> m;
 
        while (n > 0)
        {
            d= m;
            while (d > 0)
            {

                printf("%d", c);
                ++c;
                --d;
                if (c == 4)
                {
                    c = 0;
                }

            }
            printf("\n");
            n--;
        }




    }

}
